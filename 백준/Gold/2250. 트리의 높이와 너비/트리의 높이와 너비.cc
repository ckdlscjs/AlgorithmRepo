/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, pos = 1, reslev, reswidth, indegree[10'005], root;
std::map<int, std::set<int>> widths;
std::vector<std::pair<int, int>> tree;
void LDR(int cur, int depth)
{
    if(tree[cur].first != -1) LDR(tree[cur].first, depth+1);
    //std::cout << cur << ", " << depth << " : " << pos << '\n';
    widths[depth].insert(pos++);
    if(tree[cur].second != -1) LDR(tree[cur].second, depth+1);
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	tree.resize(N+1);
    for(int n = 0; n < N; n++)
    {
        int cur, left, right;
        std::cin >> cur >> left >> right;
        indegree[left]++;
        indegree[right]++;
        tree[cur].first = left;
        tree[cur].second = right;
    }
    for(int i = 1; i <= N; i++)
    {
        if(indegree[i] == 0)
        {
            root = i;
            break;
        }
    }
    LDR(root, 1);
    for(auto iter = widths.rbegin(); iter != widths.rend(); iter++)
    {
        if(reswidth <= *iter->second.rbegin() - *iter->second.begin() + 1)
        {
            reslev = iter->first;
            reswidth = *iter->second.rbegin() - *iter->second.begin() + 1;
        }
    }
    std::cout << reslev << ' ' << reswidth;
	return 0;
}

