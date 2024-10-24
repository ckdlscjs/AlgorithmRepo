//https://school.programmers.co.kr/learn/courses/30/lessons/92335
#include <bits/stdc++.h>
using namespace std;
bool IsPrime(long long int num)
{
    if(num < 2) return false;
    for(int i = 2; i <= std::sqrt(num); i++)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}
int solution(int n, int k) 
{
    std::string num = "";
    while(n)
    {
        num += std::to_string(n % k);
        n /= k;
    }
    int answer = 0;
    std::reverse(num.begin(), num.end());
    num += '0';
    std::string temp = "";
    for(const auto& iter : num)
    {
        if(temp.empty() && iter == '0')
            continue;
        temp += iter;
        if(temp.size() >= 2 && temp[temp.size()-1] == '0')
        {
            std::string numstr = temp.substr(0, temp.size() - 1);
            if(numstr.find('0') == std::string::npos && IsPrime(std::stoll(numstr)))
                answer++;
            temp.clear();
        }
    }
    return answer;
}