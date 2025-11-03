#include <bits/stdc++.h>
using namespace std;

string solution(vector<int> numbers) 
{
    std::vector<std::string> nums;
    for(const auto& iter : numbers)
        nums.push_back(std::to_string(iter));
    
    std::sort(nums.begin(), nums.end(), [](const std::string& a, const std::string& b){
        return (a + b) > (b + a);
    });
    string answer = "";
    for(const auto& iter : nums)
        answer += iter;
    return (answer[0] == '0') ? "0" : answer;
}