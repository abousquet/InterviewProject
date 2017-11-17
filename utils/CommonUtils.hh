#ifndef COMMON_UTILS_HH
#define COMMON_UTILS_HH

#include <iostream>
#include <set>
using namespace std;
namespace Utils {

typedef pair<int, string> Request;


std::string dataFunction(std::string data);
std::string dataProducer();

int pollWrapper(int fd, bool input=true);

int pollWrapper(set<int>& fds, bool input = true, int timeout = -1);

};

#endif
