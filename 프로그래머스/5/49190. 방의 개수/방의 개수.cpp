//https://school.programmers.co.kr/learn/courses/30/lessons/49190
#include <bits/stdc++.h>
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0 ,- 1, -1, -1};
using namespace std;
std::set<std::pair<int, int>> vertexs;
std::set<std::pair<std::pair<int, int>, std::pair<int, int>>> edges;
int solution(vector<int> arrows) 
{
    int y = 0, x = 0, answer = 0;
    vertexs.insert({y, x});
    for(const auto& dir : arrows)
    {
        for(int i = 0; i < 2; i++)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(vertexs.find({ny, nx}) != vertexs.end() && edges.find({{y, x}, {ny, nx}}) == edges.end())
                answer++;
            vertexs.insert({ny, nx});
            edges.insert({{y, x}, {ny, nx}});
            edges.insert({{ny, nx}, {y, x}});
            y = ny;
            x = nx;
        }
    }
    
    return answer;
}