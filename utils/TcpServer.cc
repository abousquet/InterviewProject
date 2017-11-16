#include "TcpServer.hh"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <iostream>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>

using namespace std;

Utils::TcpServer::TcpServer(int localPort) : TcpSocket()
{
   if (!TcpSocket::isValid())
   {
      std::cout << "Failed to create socket" << sockfd << std::endl;
   }
   struct sockaddr_in addr;

   memset(&addr, 0, sizeof addr);
   addr.sin_family = AF_INET;
   addr.sin_port = htons(localPort); // short, network byte order
   if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
   {
      std::cout << "Bind Failed " << sockfd <<": "<< errno << " " << strerror(errno) << std::endl;
   }
}

Utils::TcpServer::~TcpServer()
{}

int Utils::TcpServer::listen()
{
   return ::listen(sockfd, 5);
}

// TODO - Task 2
int Utils::TcpServer::accept()
{
   // Write code for Task 2
   int newfd = ::accept(sockfd, NULL, NULL);
   if (newfd >= 0)
   {
      return newfd;
   }
   else
   {
      return 0;
   }
}
