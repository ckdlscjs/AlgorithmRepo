//https://school.programmers.co.kr/learn/courses/30/lessons/60062
#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) 
{
    int len = weak.size();
    for(int i = 0; i < len; i++) weak.push_back(n + weak[i]);
    int answer = dist.size() + 1;
    do
    {
        for(int i = 0; i < weak.size() / 2; i++)
        {
            int cnt = 0;
            int pos = weak[i] + dist[cnt];
            for(int j = i + 1; j < i+weak.size()/2; j++)
            {
                if(pos >= weak[j]) continue;
                cnt++;
                if(cnt >= dist.size()) break;
                pos = weak[j] + dist[cnt];
            }
            answer = std::min(answer, cnt + 1);
        } 
    }while(next_permutation(dist.begin(), dist.end()));
    return (answer > dist.size() ? -1 : answer);
}