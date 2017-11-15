#include "RequestQueue.hh"

namespace Utils{

RequestQueue::RequestQueue():
   queueMutex(), requestQueue()
{}
RequestQueue::~RequestQueue()
{}

/**
*    TODO - Task 5
*    Make all non-constructor/deconstructor functions thread safe.
**/
void RequestQueue::push( Request data)
{
   requestQueue.push(data);
}
Request RequestQueue::pop()
{
   if (!requestQueue.empty())
   {
      Request retVal = requestQueue.front();
      requestQueue.pop();
      return retVal;
   }
   else
   {
      return Request(-1, "");
   }
}

bool RequestQueue::isEmpty()
{
   return requestQueue.empty();
}

}
