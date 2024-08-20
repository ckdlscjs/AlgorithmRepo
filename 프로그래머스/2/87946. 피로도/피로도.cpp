#include <bits/stdc++.h>
using namespace std;
int result;
bool visited[10];
void check(int idx, int cnt, int k, const std::vector<std::vector<int>>& dungeons)
{
    if(idx >= dungeons.size())
    {
        result = std::max(result, cnt);
        return;
    }
    for(int i = 0; i < dungeons.size(); i++)
    {
        if(visited[i])
            continue;
        if(k < dungeons[i][0])
            continue;
        visited[i] = true;
        check(idx+1, cnt+1, k - dungeons[i][1], dungeons);
        visited[i] = false;
    }
    check(idx+1, cnt, k, dungeons);
}
int solution(int k, vector<vector<int>> dungeons) 
{
    check(0, 0, k, dungeons);
    return result;
}