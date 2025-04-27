#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
std::unordered_map<char, int> dir;
int N, M;
std::string arr[1'005];
std::set<std::pair<int, int>> cnts;
struct DisjointSet
{
    std::vector<std::vector<std::pair<int, int>>> parents;
    std::vector<std::vector<int>> ranks;
    DisjointSet(int _N, int _M) : parents(std::vector(_N, std::vector(_M, std::make_pair(-1, -1)))), ranks(std::vector(_N, std::vector(_M, 0))) {}
    std::pair<int, int> Find(std::pair<int, int> v)
    {
      if(parents[v.first][v.second].first == -1 && parents[v.first][v.second].second == -1) return v;
      return parents[v.first][v.second] = Find(parents[v.first][v.second]);
    }
    void Union(std::pair<int, int> v1, std::pair<int, int> v2)
    {
        std::pair<int, int> root1 = Find(v1);
        std::pair<int, int> root2 = Find(v2);
        if(root1.first == root2.first && root1.second == root2.second) return;
        if(ranks[root1.first][root1.second] == ranks[root2.first][root2.second])
        {
            parents[root2.first][root2.second] = root1;
            ranks[root1.first][root1.second]++;
        }
        else if(ranks[root1.first][root1.second] > ranks[root2.first][root2.second])
        {
            parents[root2.first][root2.second] = root1;
        }
        else
        {
            parents[root1.first][root1.second] = root2;
        }
    }
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    dir['U'] = 0; dir['D'] = 1; dir['L'] = 2; dir['R'] = 3;
    std::cin >> N >> M;
    DisjointSet ds(N, M);

    for(int n = 0; n < N; n++) std::cin >> arr[n];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            char order = arr[i][j];
            int ny = i + dy[dir[order]];
            int nx = j + dx[dir[order]];
            ds.Union({i, j}, {ny, nx});
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cnts.insert(ds.Find({i, j}));
        }
    }
    std::cout << cnts.size();
    return 0;
}