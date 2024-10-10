//school.programmers.co.kr/learn/courses/30/lessons/12981
#include <bits/stdc++.h>
using namespace std;
std::unordered_set<std::string> chks;
vector<int> solution(int n, vector<string> words) 
{
    int cnt = 0;
    char ch = '0';
    for(int i = 0; i < words.size(); i++)
    {
        if(chks.find(words[i]) != chks.end())
            break;
        if(i >= 1 && words[i][0] != ch)
            break;
        ch = *words[i].rbegin();
        cnt++;
        chks.insert(words[i]);
    }
    std::vector<int> answer(2, 0);
    if(cnt < words.size())
    {
        answer[0] = (cnt%n)+1;
        answer[1] = cnt/n + 1;
    }
    return answer;
}