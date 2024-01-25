#include <bits/stdc++.h>
using namespace std;
std::unordered_map<char, int> inputs;
string solution(vector<string> survey, vector<int> choices) 
{
    for(int i = 0; i < survey.size(); i++)
    {
        if(choices[i] == 4)
            continue;
        if(choices[i] > 4)
            inputs[survey[i][1]] += choices[i] - 4;
        else
            inputs[survey[i][0]] += 4 - choices[i];
    }
    std::string answer;
    answer += inputs['R'] == inputs['T'] ? 'R' : inputs['R'] < inputs['T'] ? 'T' : 'R';
    answer += inputs['C'] == inputs['F'] ? 'C' : inputs['C'] < inputs['F'] ? 'F' : 'C';
    answer += inputs['J'] == inputs['M'] ? 'J' : inputs['J'] < inputs['M'] ? 'M' : 'J';
    answer += inputs['A'] == inputs['N'] ? 'A' : inputs['A'] < inputs['N'] ? 'N' : 'A';
    return answer;
}