/*
접근방식:

시간복잡도:

*/

#include <bits/stdc++.h>
int N, a, b, c, cnt, endnode;
std::pair<int, int> tree[100'005];
void InOrder(int node)
{
    if(tree[node].first != -1)
        InOrder(tree[node].first);
    cnt++;
    if(cnt >= N)
        endnode = node;
    if(tree[node].second != -1)
        InOrder(tree[node].second);
}
bool flag = false;
void Check(int node)
{
    if(tree[node].first != -1)
    {
        cnt++;
        Check(tree[node].first);
        if(!flag) cnt++;
    }
    if(tree[node].second != -1)
    {
        cnt++;
        Check(tree[node].second);
        if(!flag)  cnt++;
    }
    if(node == endnode)
        flag = true;
}

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++)
    {
        std::cin >> a >> b >> c;
        tree[a].first = b;
        tree[a].second = c;
    }
    InOrder(1);
    cnt = 0;
    //std::cout << endnode;
    Check(1);
    std::cout << cnt;
    return 0;
}
