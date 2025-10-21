#include <bits/stdc++.h>
using namespace std;
int trees[26];
int solution(string skill, vector<string> skill_trees) 
{
    int answer = 0;
    int idx = 1;
    for(const auto& iter : skill) trees[iter-'A'] = idx++;
    for(const auto& str : skill_trees)
    {
        int cur = 0;
        int i = 0;
        for(i = 0; i < str.size(); i++)
        {
            if(trees[str[i]-'A'] < cur || trees[str[i]-'A'] == 0) continue;
            if(trees[str[i]-'A'] == cur + 1) cur++;
            else break;
        }
        if(i >= str.size())
            answer++;
    }
    return answer;
}