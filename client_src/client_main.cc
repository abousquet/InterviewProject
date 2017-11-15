#include "TcpClient.hh"
#include "CommonUtils.hh"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <poll.h>

using namespace std;

int main(int argc, char** argv)
{
   if (argc != 2)
   {
      cout << "Usage: " << argv[0] << " <port>" << endl;
      return 1;
   }
   int port = atoi(argv[1]);
   Utils::TcpClient client;
   if (!client.connect(port))
   {
      cout << "Failed to connect to " << port << ":" << strerror(errno) << endl;
   }
   else
   {
      cout << "Client connected successfully" << endl;
      bool stopReading = false;
      while (!stopReading)
      {
         char *line = NULL;
         bool useLine = true;
         string producedData;
         size_t size;
         int getLineVal;
         if ((getLineVal = getline(&line, &size, stdin)) < 2) {

            producedData = Utils::dataProducer();
            cout << "Generated Password: " << producedData << endl;
            useLine = false;
         }
         if (client.pollForOutput() >= 1)
         {
            if (useLine)
            {
               client.send(line, getLineVal - 1);
            }
            else
            {
               client.send(producedData);
            }
            if ( client.pollForInput() >= 1)
            {
               string str;
               client.receive(str);
               cout << "Password strength is: "<< str << endl;
            }
            else
            {
               stopReading = true;
            }
         }
         else{
            stopReading = true;
         }
         if (stopReading)
         {
            cout << "Something happened while polling: closing..." << endl;
         }

         free(line);
      }
   }
   return 0;
}
