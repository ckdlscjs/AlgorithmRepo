#include <bits/stdc++.h>

using namespace std;
void dfs(const std::string& tree, std::string& visited, int cur, int size)
{
    if(tree[cur] == '0') return;
    visited[cur] = '1';
    if(size <= 0) return;
    if(0 <= cur - size/2 && tree[cur - size/2] == '1') dfs(tree, visited, cur - size/2, size/2);
    if(cur + size/2 <= tree.size()-1 && tree[cur + size/2] == '1') dfs(tree, visited, cur + size/2, size/2);
}
vector<int> solution(vector<long long> numbers) 
{
    
    vector<int> answer;
    for(const auto& iter : numbers)
    {
        long long cur = iter;
        std::string visited;
        std::string str;
        while(cur)
        {
            if(cur % 2) str += '1';
            else str += '0';
            cur >>= 1;
        }
        int size = str.size();
        int depth = 0;
        while(size)
        {
            size >>= 1;
            depth++;
        }
        size = (1 << depth) - 1;
        while(str.size() < size) str += '0';
        //td::cout << str << '\n';
        visited.resize(str.size(), '0');
        dfs(str, visited, str.size()/2, str.size()/2+1);
        answer.push_back(visited == str ? 1 : 0);
    }
    
    return answer;
}