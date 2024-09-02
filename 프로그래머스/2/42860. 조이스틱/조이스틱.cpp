#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
    std::unordered_map<char, int> alps;
    for(int i = 0; i < 26; i++)
    {
        if(i <= 13)
            alps[i + 'A'] = i;
        else
            alps[i+'A'] = 26 - i;
    }
    int answer = name.size()-1;
    for(int i = 0; i < name.size(); i++)
    {
        int cursor = i+1;
        while(cursor < name.size() && name[cursor] == 'A') cursor++;
        answer = std::min(answer, (int)(i*2 + name.size() - cursor));
        answer = std::min(answer, (int)(i + (name.size() - cursor) * 2));
    }
    
    for(const auto& iter : name)
        answer += alps[iter];
    return answer;
}