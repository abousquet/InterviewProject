#ifndef TCP_SOCKET_HH
#define TCP_SOCKET_HH


namespace Utils {

class TcpSocket{
public:

   TcpSocket();
   TcpSocket(int fd);
   ~TcpSocket();

   bool isValid();

   int getFd();

protected:
   int sockfd;
};
};
#endif
