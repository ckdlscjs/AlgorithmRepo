#include <bits/stdc++.h>
using namespace std;
std::unordered_map<std::string, int> cnts;
bool IsValid(const std::vector<std::string>& want, const std::vector<int>& number)
{
    for(int i = 0; i < want.size(); i++)
    {
        if(cnts[want[i]] < number[i])
            return false;
    }
    return true;
}
int solution(vector<string> want, vector<int> number, vector<string> discount) 
{
    for(int i = 0; i < 10; i++) cnts[discount[i]]++;
    int answer = IsValid(want, number);
    for(int i = 10; i < discount.size(); i++)
    {
        cnts[discount[i-10]]--;
        cnts[discount[i]]++;
        if(IsValid(want, number)) answer++;
    }
    return answer;
}