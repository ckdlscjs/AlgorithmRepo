#include <bits/stdc++.h>
using namespace std;
std::unordered_map<std::string, int> cnts;
int solution(vector<vector<string>> clothes) 
{
    int answer = 1;
    for(const auto& strs : clothes) cnts[strs[1]]++;
    for(const auto& cnt : cnts)
        answer *= (cnt.second+1);
    return answer - 1;
}