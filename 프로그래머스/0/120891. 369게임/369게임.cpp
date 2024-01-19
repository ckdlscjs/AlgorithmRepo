#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int order) 
{
    int answer = 0;
    while(order)
    {
        std::cout << order <<'\n';
        int temp = order % 10;
        if(temp && temp % 3 == 0)
            answer++;
        order /= 10;
    }
    
    return answer;
}