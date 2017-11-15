#ifndef TCP_SERVER_HH
#define TCP_SERVER_HH

#include <string>
#include "TcpSocket.hh"
#include "TcpClient.hh"

namespace Utils
{

class TcpServer : public TcpSocket
{
public:
   TcpServer(int localPort);
   ~TcpServer();

   int listen();

   int accept();

};
};
#endif
