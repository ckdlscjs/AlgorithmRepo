#include <bits/stdc++.h>
using namespace std;
std::unordered_set<int> num[10];
int solution(int N, int number) 
{
    int answer = -1;
    int sum = 0;
    for(int i = 1; i <= 8; i++)
    {
        sum = 10*sum + N;
        num[i].insert(sum);
    }
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 0; j < i; j++)
        {
            for(int a : num[j])
            {
                for(int b : num[i-j])
                {
                    num[i].insert(a+b);
                    num[i].insert(a-b);
                    num[i].insert(a*b);
                    if(b != 0)
                        num[i].insert(a/b);
                }
            }
        }
    }
    for(int i = 1; i <= 8; i++)
    {
        if(num[i].find(number) != num[i].end())
        {
            answer = i;
            break;
        }
    }
    return answer;
}