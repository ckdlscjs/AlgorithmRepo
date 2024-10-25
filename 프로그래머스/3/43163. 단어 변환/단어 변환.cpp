//https://school.programmers.co.kr/learn/courses/30/lessons/43163
#include <bits/stdc++.h>
using namespace std;
std::unordered_set<char> alps[12];
std::unordered_map<std::string, int> chks;
int solution(string begin, string target, vector<string> words) 
{
    for(const auto& iter : words)
    {
        chks[iter] = 0;
        for(int i = 0; i < iter.size(); i++)
            alps[i].insert(iter[i]);
    }
        
    if(chks.find(target) == chks.end()) return 0;
    std::queue<std::string> q;
    chks[begin] = 1;
    q.push(begin);
    while(q.size())
    {
        std::string cur = q.front();
        q.pop();
        for(int idx = 0; idx < cur.size(); idx++)
        {
            for(const auto& iter : alps[idx])
            {
                std::string temp = cur;
                temp[idx] = iter;
                if(chks.find(temp) == chks.end() || chks[temp])
                    continue;
                chks[temp] = chks[cur] + 1;
                q.push(temp);
            }
        }
    }
    return chks[target] - 1;
}