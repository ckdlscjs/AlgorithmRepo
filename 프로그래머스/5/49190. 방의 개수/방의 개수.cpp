#include <bits/stdc++.h>
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
/*
1.정점의 재방문
2.정점의 재방문시 사용이 안된간선이어야함
3.범위를 * 2로 두번씩 간선을 추가하면서 계산하여 중간의 교차지점을 섞는다 (모래시계형태)
*/
using namespace std;
std::set<std::pair<int, int>> vertexs;
std::set<std::pair<std::pair<int, int>, std::pair<int, int>>> edges;
int solution(vector<int> arrows) 
{
    int answer = 0;
    int y = 0, x = 0;
    vertexs.insert({y, x});
    for(const auto& dir : arrows)
    {
       for(int cnt = 0; cnt < 2; cnt++)
       {
           int ny = y + dy[dir];
           int nx = x + dx[dir];
           if(vertexs.find({ny, nx}) == vertexs.end())
           {
               vertexs.insert({ny, nx});
               edges.insert({{y, x}, {ny, nx}});
               edges.insert({{ny, nx}, {y, x}});
           }
           else
           {
               if(edges.find({{y, x}, {ny, nx}}) == edges.end())
               {
                   answer++;
                   edges.insert({{y, x}, {ny, nx}});
                   edges.insert({{ny, nx}, {y, x}});
               }
           }
           y = ny;
           x = nx;
       }
    }
    
    return answer;
}