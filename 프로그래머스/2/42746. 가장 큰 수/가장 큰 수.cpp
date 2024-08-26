#include <bits/stdc++.h>
using namespace std;

bool compare(const int& a, const int& b)
{
    std::string st1 = std::to_string(a);
    std::string st2 = std::to_string(b);
    return std::stoi(st1+st2) > std::stoi(st2+st1);
}
string solution(vector<int> numbers) 
{
    std::sort(numbers.begin(), numbers.end(), compare);
    string answer = "";
    for(const auto& iter : numbers)
        answer += std::to_string(iter);
    return answer[0] == '0' ? "0" : answer;
}