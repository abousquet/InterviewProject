#ifndef REQUEST_QUEUE_HH
#define REQUEST_QUEUE_HH

#include <mutex>
#include <queue>
#include <string>
#include "CommonUtils.hh"
using namespace std;

namespace Utils {

class RequestQueue
{
public:
   RequestQueue();
   ~RequestQueue();

   void push( Request data);
   Request pop();
   bool isEmpty();

private:
   mutex queueMutex;
   queue<Request> queue;
};

};

#endif
