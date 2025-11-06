#include <bits/stdc++.h>
using namespace std;
std::unordered_set<int> notprimes;
std::unordered_set<int> strs;
void Check(const std::string& nums, std::string& str, int mask)
{
    if(str.size())
        strs.insert(std::stoi(str));
    if(str.size() >= nums.size()) return;
    for(int i = 0; i < nums.size(); i++)
    {
        if(mask & (1 << i)) continue;
        str += nums[i];
        Check(nums, str, mask | 1 << i);
        str.pop_back();
    }
}
int solution(string numbers) 
{
    notprimes.insert(0);
    notprimes.insert(1);
    for(int i = 2; i <= std::sqrt(10'000'000); i++)
    {
        if(notprimes.find(i) != notprimes.end()) 
            continue;
        for(int j = 2; i * j < 10'000'000; j++)
            notprimes.insert(i * j);
    }
    std::string s;
    Check(numbers, s, 0);
    int answer = 0;
    
    for(const auto& str : strs)
        if(notprimes.find(str) == notprimes.end())
        {
            //std::cout << stoi(str) << '\n';
            answer++;
        }
            
            
    return answer;
}