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

string Utils::dataFunction(string data)
{
  /**
  *   TODO - Task 2
  *   This function accepts a string password as a parameter and returns a string
  *   representing the strength of the password parameter denoted by
  *   STRONG_STRING, MEDIUM_STRING, WEAK_STRING and INVALID_STRING . The strength
  *   of the password can be determined using the following rules:
  *   1) The password contains a lowercase letter
  *   2) The password contains an uppercase letter
  *   3) The password contains a special character !@#$%^&*()-+
  *   4) The password is atleast 12 characters long
  *   5) The password contains a digit
  *   A password is considered STRONG if it meets all of the above conditions. A
  *   password is considered MEDIUM if it meets conditions 1-3 and is atleast 9
  *   characters long. A password is considered WEAK in all other cases. A
  *   password is considered INVALID if it is empty or contains a character that
  *   does not satisfy conditions 1, 2, 3 or 5.
  *
  **/

   return data; // placed here to get rid of warnings
}

string Utils::dataProducer()
{
  /**
  *   TODO - Task 3
  *   This function generates a random password string consisting of the valid
  *   characters defined in Task 2. The string will be of random length between 6
  *   and 15 characters long. Ensure that the function will not generate the same
  *   password if many calls are made in the same second.
  *
  **/

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
