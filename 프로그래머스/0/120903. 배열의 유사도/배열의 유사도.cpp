#include <bits/stdc++.h>
using namespace std;
std::map<std::string, int> map_s1;
int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    
    for(const auto& str : s1)
        map_s1[str]++;
    
    for(const auto& str : s2)
    {
        if(map_s1[str])
            answer++;
    }
    return answer;
}