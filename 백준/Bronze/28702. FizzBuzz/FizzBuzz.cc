/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
std::string str[3];
std::string makestr(int num)
{
    if(num % 3 == 0 && num % 5 == 0) return "FizzBuzz";
    else if(num % 3 == 0 && num % 5 != 0) return "Fizz";
    else if(num % 3 != 0 && num % 5 == 0) return "Buzz";
    else return std::to_string(num);
}
int main()
{
    std::cin >> str[0] >> str[1] >> str[2];
    if(str[0] != "FizzBuzz" && str[0] != "Fizz" && str[0] != "Buzz") std::cout << makestr(std::stoi(str[0]) + 3);
    else if(str[1] != "FizzBuzz" && str[1] != "Fizz" && str[1] != "Buzz") std::cout << makestr(std::stoi(str[1]) + 2);
    else std::cout << makestr(std::stoi(str[2]) + 1);
    return 0;
}