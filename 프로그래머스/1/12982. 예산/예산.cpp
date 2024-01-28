#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> d, int budget) {
    std::sort(d.begin(), d.end());
    int answer = 0;
    for(const int& num : d)
    {
        budget -= num;
        if(budget < 0)
            break;
        answer++;
       
    }
    
    return answer;
}