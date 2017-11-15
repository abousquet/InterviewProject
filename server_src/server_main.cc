#include <iostream>
#include "TcpServer.hh"
#include "TcpClient.hh"
#include "CommonUtils.hh"
#include "RequestQueue.hh"
#include <errno.h>
#include <string.h>
#include <poll.h>
#include <vector>
#include <unistd.h>
#include <pthread.h>
#include <set>

using namespace std;

void * main_read_t(void * data);
void * main_write_t(void * data);
void * main_data_t(void * data);

Utils::RequestQueue toReadThread;
Utils::RequestQueue toWriteThread;
Utils::RequestQueue toDataThread;


using namespace std;

int main (int argc, char ** argv)
{
   if (argc < 2)
   {
      cout << "Usage: " << argv[0] << " <port>" << endl;
      return 1;
   }
   int port = atoi(argv[1]);
   Utils::TcpServer server (port);

   // TODO - Task 7

   cout << "Listening for connection on " <<port <<"..." << endl;
   if (server.listen() == 0)
   {
      int numClients = 0;
      while (numClients < 10)
      {
         int fd = server.accept();
         if (fd)
         {
            toReadThread.push(Utils::Request(fd, ""));
            ++numClients;
         }
      }
      cout << "Closing because reached 10 clients" << endl;
   }
   else{
      cout << "Listen unsuccessful: " << strerror(errno) << endl;
   }

   return 0;
}

void * main_read_t(void * data)
{
   set<int> readingSet;
   while (true)
   {
      while (!toReadThread.isEmpty())
      {
         int newFd = toReadThread.pop().first;
         if (newFd == -1) //this is returned when the RequestQueue is empty
         {
            break;
         }
         readingSet.insert(newFd);
      }
      int fdToRead = Utils::pollWrapper(readingSet, true, 50);
      if (fdToRead > 0)
      {
         Utils::TcpClient client(fdToRead);
         string password;
         if (client.receive(password))
         {
            toDataThread.push(Utils::Request(client.getFd(), password));
            readingSet.erase(client.getFd());
         }
      }
   }
   return NULL;
}
void * main_write_t(void * data)
{
   while (true)
   {
      while (!toWriteThread.isEmpty())
      {
         Utils::Request request = toWriteThread.pop();
         if (request.first == -1) //this is returned when the RequestQueue is empty
         {
            break;
         }
         Utils::TcpClient client(request.first);
         if (client.pollForOutput() > 0)
         {
            client.send(request.second);
            toReadThread.push(Utils::Request(client.getFd(), ""));
         }
      }
   }
   return NULL;
}
void * main_data_t(void * data)
{
   while (true)
   {
      while (!toDataThread.isEmpty())
      {
         Utils::Request request = toDataThread.pop();
         if (request.first == -1) // RequestQueue is actually empty
         {
            break;
         }
         string strength = Utils::dataFunction(request.second);
         toWriteThread.push(Utils::Request(request.first, strength));
      }
   }
   return NULL;
}
