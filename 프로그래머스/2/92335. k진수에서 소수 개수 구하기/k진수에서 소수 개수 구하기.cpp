#include <bits/stdc++.h>

using namespace std;
bool isPrime(const std::string& str)
{
    long long cur = std::stoll(str);
    if(cur < 2) return false;
    for(long long i = 2; i <= std::sqrt(cur); i++)
    {
        if(cur % i == 0) 
            return false;
    }
    return true;
}
int solution(int n, int k) 
{
    
    std::string str;
    while(n)
    {
        str += std::to_string(n % k);
        n /= k;
    }
    
    std::reverse(str.begin(), str.end());
    str += '0';
    //std::cout << str;
    int answer = 0;
    std::string num = "";
    for(const auto& ch : str)
    {
        if(ch == '0')
        {
            if(num.size() && isPrime(num))
                answer++;
            num.clear();
            continue;
        }
        num += ch;
    }
    
    return answer;
}