#include <bits/stdc++.h>
using namespace std;
const int MaxN = 15;
int peoples[MaxN];
std::unordered_set<std::string> checks;
vector<int> solution(int n, vector<string> words) 
{
    int cur = 1;
    char last_ch = words[0][0];
    for(const std::string& word : words)
    {
        peoples[cur]++;
        if(word[0] != last_ch || checks.find(word) != checks.end())
            return {cur, peoples[cur]};
        checks.insert(word);
        last_ch = word[word.size()-1];
        cur++;
        if(cur > n)
            cur = 1;
    }

    return {0, 0};
}