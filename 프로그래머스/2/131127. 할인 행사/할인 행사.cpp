#include <bits/stdc++.h>
using namespace std;
std::unordered_map<std::string, int> wants;
bool Check(const vector<string>& want, const vector<int>& number)
{
    for(int i = 0; i < want.size(); i++)
    {
        if(wants[want[i]] < number[i])
            return false;
    }
    return true;
}
int solution(vector<string> want, vector<int> number, vector<string> discount) 
{
    discount.insert(discount.begin(), "temp");
    for(int i = 0; i < 10; i++)
        wants[discount[i]]++;
    int answer = 0;
    for(int i = 10; i < discount.size(); i++)
    {
        wants[discount[i-10]]--;
        wants[discount[i]]++;
        if(Check(want, number))
            answer++;
    }
    return answer;
}