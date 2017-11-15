#include "RequestQueue.hh"

namespace Utils{

RequestQueue::RequestQueue():
   queueMutex(), queue()
{}
RequestQueue::~RequestQueue()
{}

/**
*    TODO - Task 5
*    Make all non-constructor/deconstructor functions thread safe.
**/
void RequestQueue::push( Request data)
{
   queue.push(data);
}
Request RequestQueue::pop()
{
   if (!queue.empty())
   {
      Request retVal = queue.front();
      queue.pop();
      return retVal;
   }
   else
   {
      return Request(-1, "");
   }
}

bool RequestQueue::isEmpty()
{
   return queue.empty();
}

}
