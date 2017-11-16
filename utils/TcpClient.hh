#ifndef TCP_CLIENT_HH
#define TCP_CLIENT_HH

#include <string>
#include "TcpSocket.hh"

namespace Utils
{

class TcpClient : public TcpSocket
{
public:
   TcpClient();
   TcpClient(int fd);
   ~TcpClient();

   bool connect(int remotePort);

   int pollForInput();
   int pollForOutput();

   void send(const std::string& data);
   void send(const char * data, size_t length);

   size_t receive(std::string& data);
   size_t receive(char * data, size_t length);
};
};
#endif
