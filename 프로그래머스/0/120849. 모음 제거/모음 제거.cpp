#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string my_string) {
    while(my_string.find('a') != std::string::npos)
    {
        my_string.erase(my_string.find('a'), 1);
    }
    while(my_string.find('e') != std::string::npos)
    {
        my_string.erase(my_string.find('e'), 1);
    }
    while(my_string.find('i') != std::string::npos)
    {
        my_string.erase(my_string.find('i'), 1);
    }
    while(my_string.find('o') != std::string::npos)
    {
        my_string.erase(my_string.find('o'), 1);
    }
    while(my_string.find('u') != std::string::npos)
    {
        my_string.erase(my_string.find('u'), 1);
    }
    return my_string;
}