//https://school.programmers.co.kr/learn/courses/30/lessons/118666
#include <bits/stdc++.h>
using namespace std;
std::unordered_map<char, int> table;
string solution(vector<string> survey, vector<int> choices) 
{
    table['R'] = table['T'] = table['C'] = table['F'] = table['J'] = table['M'] = table['A'] = table['N'] = 0;
    for(int i = 0; i < survey.size(); i++)
    {
        if(choices[i] < 4)
            table[survey[i][0]] += 4 - choices[i];
        else if(choices[i] > 4)
            table[survey[i][1]] += choices[i] - 4;
    }
    string answer = "";
    answer += table['R'] == table['T'] ? 'R' : table['R'] > table['T'] ? 'R' : 'T';
    answer += table['C'] == table['F'] ? 'C' : table['C'] > table['F'] ? 'C' : 'F';
    answer += table['J'] == table['M'] ? 'J' : table['J'] > table['M'] ? 'J' : 'M';
    answer += table['A'] == table['N'] ? 'A' : table['A'] > table['N'] ? 'A' : 'N';
    return answer;
}