#include <bits/stdc++.h>

using namespace std;
char arr[3] = {'4', '1', '2'};
string solution(int n) 
{
    string answer = "";
    while(n)
    {
        answer += arr[n % 3];
        if(n % 3 == 0) n = (n/3) - 1;
        else n /= 3;
    }
    std::reverse(answer.begin(), answer.end());
    return answer;
}