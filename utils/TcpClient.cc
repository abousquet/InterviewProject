#include "TcpClient.hh"
#include "CommonUtils.hh"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

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
   // Write code for Task 3

   return false; // placed here to get rid of warnings
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
