#include "RequestQueue.hh"

namespace Utils{

RequestQueue::RequestQueue():
   queueMutex(), rqueue()
{}
RequestQueue::~RequestQueue()
{}

/**
*    TODO - Task 4
*    Make all non-constructor/deconstructor functions thread safe.
**/
void RequestQueue::push( Request data)
{
   rqueue.push(data);
}
Request RequestQueue::pop()
{
   if (!rqueue.empty())
   {
      Request retVal = rqueue.front();
      rqueue.pop();
      return retVal;
   }
   else
   {
      return Request(-1, "");
   }
}

bool RequestQueue::isEmpty()
{
   return rqueue.empty();
}

}
