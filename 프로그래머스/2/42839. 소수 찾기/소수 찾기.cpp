#include <bits/stdc++.h>
using namespace std;
std::unordered_set<int> primes;
void Check(const std::string& nums, std::string str, int used)
{
    if(str.size())
    {
        int num = std::stoi(str);
        if(num >= 2)
        {
            bool chk = true;
            for(int i = 2; i <= std::sqrt(num); i++)
            {
                if(num%i == 0)
                {
                    chk = false;
                    break;
                } 
            }
            if(chk)
                primes.insert(num);
        }
    }
    for(int i = 0; i < nums.size(); i++)
    {
        if(used & (1 << i))
            continue;
        Check(nums, str+nums[i], used | 1<<i);
    }
}
int solution(string numbers) 
{
    std::stable_sort(numbers.begin(), numbers.end(), std::less<>());
    Check(numbers, {}, 0);
    return primes.size();
}