#include <bits/stdc++.h>
using namespace std;
std::unordered_map<std::string, int> chks;
std::queue<std::string> q;
bool CalcDiif(const std::string& str1, const std::string& str2)
{
    int cnt = 0;
    for(int i = 0; i < str1.size(); i++)
    {
        if(str1[i] == str2[i]) continue;
        cnt++;
        if(cnt >= 2) return false;
    }
    return true;
}
int solution(string begin, string target, vector<string> words) 
{
    for(int i = 0; i < words.size(); i++)
        chks[words[i]] = 0;
    if(chks.find(target) == chks.end()) return 0;
    chks[begin] = 1;
    q.push(begin);
    while(q.size())
    {
        auto cur = q.front();
        q.pop();
        for(const auto& iter : words)
        {
            if(iter == cur) continue;
            if(chks[iter] > 0) continue;
            if(!CalcDiif(cur, iter)) continue;
            chks[iter] = chks[cur] + 1;
            q.push(iter);
        }
    }
    return chks[target] >= 1 ? chks[target] -1 : 0;
}