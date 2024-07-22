#include <bits/stdc++.h>
using namespace std;
int solution(vector<vector<string>> clothes) 
{
    std::unordered_map<std::string, std::vector<std::string>> hash_map;
    int answer = 1;
    for(int i = 0; i < clothes.size(); i++)
        hash_map[clothes[i][1]].push_back(clothes[i][0]);
        
    for(const auto& iter : hash_map)
        answer *= iter.second.size() + 1;
    
    return answer-1;
}