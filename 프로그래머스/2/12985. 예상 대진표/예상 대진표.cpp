#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    a--;
    b--;
    int answer = 0;
    while(a != b)
    {
        a >>= 1;
        b >>= 1;
        answer++;
    }
    return answer;
}