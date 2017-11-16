#include "TcpClient.hh"
#include "CommonUtils.hh"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

Utils::TcpClient::TcpClient() : TcpSocket()
{
}
Utils::TcpClient::TcpClient(int fd) : TcpSocket(fd)
{
}

Utils::TcpClient::~TcpClient()
{
}

bool Utils::TcpClient::connect(int remotePort)
{
   struct sockaddr_in serv_addr;
   memset(&serv_addr, 0, sizeof serv_addr);
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_port = htons(remotePort); // short, network byte order
   return ::connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0;
}

int Utils::TcpClient::pollForInput()
{
   return Utils::pollWrapper(getFd());
}


int Utils::TcpClient::pollForOutput()
{
   return Utils::pollWrapper(getFd(), false);
}

void Utils::TcpClient::send(const std::string& data)
{
   send(data.c_str(), data.size());
}
void Utils::TcpClient::send(const char * data, size_t length)
{
   ::write(sockfd, &length, 1);
   ::write(sockfd, data, length);
}

size_t Utils::TcpClient::receive(std::string& data)
{
   static const size_t maxLength = 100;
   char tempData [maxLength] = {0};
   size_t length = receive(tempData, maxLength);
   data.append(tempData, length);
   return length;
}
size_t Utils::TcpClient::receive(char * data, size_t length)
{
   unsigned char size = 0;
   ::read(sockfd, &size, 1);
   return ::read(sockfd, data, length);
}
