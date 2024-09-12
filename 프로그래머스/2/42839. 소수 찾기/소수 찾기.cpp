#include <bits/stdc++.h>
using namespace std;
bool IsNotPrimes[10000000];
std::unordered_set<int> primes;
bool IsPrime(int num)
{
    if(num < 2) return false;
    for(int i = 2; i <= std::sqrt(num); i++)
        if(num%i == 0)
            return false;
    return true;   
}
void Check(const std::string& nums, std::string str, int used)
{
    if(str.size())
    {
        int num = std::stoi(str);
        if(!IsNotPrimes[num])
            primes.insert(num);
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
    IsNotPrimes[0] = IsNotPrimes[1] = true;
    for(int i = 2; i < 10000000; i++)
    {
        if(IsNotPrimes[i])
            continue;
        for(int j = i*2; j < 10000000; j+=i)
            IsNotPrimes[j] = true;
    }
    std::stable_sort(numbers.begin(), numbers.end(), std::less<>());
    Check(numbers, {}, 0);
    return primes.size();
}