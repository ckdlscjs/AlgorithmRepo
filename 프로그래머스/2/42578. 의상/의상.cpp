//https://school.programmers.co.kr/learn/courses/30/lessons/42578
#include <bits/stdc++.h>
using namespace std;
std::unordered_map<std::string, std::vector<std::string>> categorys;
int solution(vector<vector<string>> clothes) 
{
    for(const auto& iter : clothes)
        categorys[iter[1]].push_back(iter[0]);
    int answer = 1;
    for(const auto& iter : categorys)
        answer *= iter.second.size()+1;
    return answer - 1;
}