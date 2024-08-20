#include <bits/stdc++.h>
using namespace std;
std::vector<char> words = {'A', 'E', 'I', 'O', 'U'};
std::unordered_map<std::string, int> results;
int idx = 0;
void check(std::string str)
{
    if(str.size() > 5)
        return;
    if(str.size())
        results[str] = idx;
    idx++;
    for(const auto& iter : words)
        check(str + iter);
}
int solution(string word) 
{   
    check({});
    return results[word];
}