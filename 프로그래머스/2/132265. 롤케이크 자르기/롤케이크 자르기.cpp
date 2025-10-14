#include <bits/stdc++.h>
using namespace std;
std::unordered_map<int, int> l, r;
int solution(vector<int> topping) 
{
    int answer = 0;
    for(const auto& iter : topping)
        r[iter]++;
    for(const auto& iter : topping)
    {
        l[iter]++;
        r[iter]--;
        if(r[iter] <= 0)
            r.erase(iter);
        if(l.size() == r.size()) answer++;
    }
    return answer;
}