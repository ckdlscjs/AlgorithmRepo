#include <bits/stdc++.h>

using namespace std;
std::unordered_set<std::string> chks;
vector<int> solution(int n, vector<string> words) 
{
    char ch = words[0][0];
    for(int i = 0; i < words.size(); i++)
    {
        if(chks.find(words[i]) != chks.end()  || ch != words[i][0])
            return {i % n + 1, i / n + 1};
        chks.insert(words[i]);
        ch = words[i].back();
    }
    
    return {0, 0};
}