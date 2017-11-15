#include "TcpSocket.hh"
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <iostream>

Utils::TcpSocket::TcpSocket()
{
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd == -1 )
   {
      std::cout << "Socket Creation Failed: " << strerror(errno) << std::endl;
      return;
   }
   int optval = 1;
   if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval) == -1)
   {
      std::cout << "Socket Option Failed: " << strerror(errno) << std::endl;
      return;
   }
}
Utils::TcpSocket::TcpSocket(int fd)
{
   sockfd = fd;
}
Utils::TcpSocket::~TcpSocket()
{

}

int Utils::TcpSocket::getFd()
{
   return sockfd;
}

bool Utils::TcpSocket::isValid()
{
   return sockfd > 0;
}
