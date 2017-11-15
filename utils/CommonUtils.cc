#include "CommonUtils.hh"
#include <iostream>
#include <poll.h>
#include <regex>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

static const string STRONG_STRING  = "STRONG";
static const string MEDIUM_STRING  = "MEDIUM";
static const string WEAK_STRING    = "WEAK";
static const string INVALID_STRING = "INVALID";

string Utils::dataFunction(string password)
{
   // Write code for Task 1

   return ""; // placed here to get rid of warnings
}

string Utils::dataProducer()
{
   // Write code for Task 2

   return ""; // placed here to get rid of warnings
}

int Utils::pollWrapper(set<int>& fds, bool input, int timeout)
{
   if (fds.empty())
   {
      return 0;
   }
   int pollVal, returnFd = 0;
   struct pollfd poll_list[fds.size()];
   size_t i = 0;
   set<int>::const_iterator iter;
   for (iter = fds.begin(); iter != fds.end(); ++iter, ++ i)
   {
      poll_list[i].fd = *iter; // fd to poll for
      if (input) //only poll for input or output
      {
         poll_list[i].events = POLLIN;
      }
      else{
         poll_list[i].events = POLLOUT;
      }
   }

   pollVal = poll(poll_list,fds.size(), timeout);
   if (pollVal < 0)
   {
      return -1;
   }
   for (i = 0; i < fds.size(); ++i) {
      if(((poll_list[i].revents&POLLHUP) == POLLHUP) ||
      ((poll_list[i].revents&POLLERR) == POLLERR) ||
      ((poll_list[i].revents&POLLNVAL) == POLLNVAL) ||
      ((poll_list[i].revents&POLLPRI) == POLLPRI))
      {
         close(poll_list[i].fd);
         fds.erase(poll_list[i].fd);
         cout << "Closing client" << endl;
      }
      else if(((poll_list[i].revents&POLLIN) == POLLIN) ||
         (poll_list[i].revents&POLLOUT) )
      {
         returnFd = poll_list[i].fd;
      }
   }
   return returnFd;
}

int Utils::pollWrapper(int fd, bool input)
{
   set<int> temp;
   temp.insert(fd);
   return pollWrapper(temp, input);


}
