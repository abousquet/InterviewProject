#ifndef COMMON_UTILS_HH
#define COMMON_UTILS_HH

#include <iostream>
#include <set>
using namespace std;
namespace Utils {

typedef pair<int, string> Request;

/**
*   TODO - Task 1
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
*   characters long. A password is considered WEAK in all other cases.
*   You cannot declare or use any boolean variables, but you may use functions
*   that return bool values. A password is considered INVALID if it contains a
*   character that does not satisfy conditions 1, 2, 3 or 5.
*
**/
std::string dataFunction(std::string password);

/**
*   TODO - Task 2
*   This function generates a random password string consisting of the valid
*   characters defined in Task 1. The string will be of random length between 6
*   and 15 characters long. Ensure that the function will not generate the same
*   password if many calls are made in the same second.
*
**/
std::string dataProducer();

int pollWrapper(int fd, bool input=true);

int pollWrapper(set<int>& fds, bool input = true, int timeout = -1);

};

#endif
