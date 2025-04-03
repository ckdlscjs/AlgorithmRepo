#include <bits/stdc++.h>
using namespace std;
int val;
std::vector<int> trees;
void PostOrder(int s, int e)
{
    if(s > e) return;
    int delim = s + 1;
    while(delim <= e)
    {
        if(trees[s] < trees[delim]) break;
        delim++;
    }
    PostOrder(s+1, delim-1);
    PostOrder(delim, e);
    std::cout << trees[s] << '\n';
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(std::cin >> val)
        trees.push_back(val);
    PostOrder(0, trees.size()-1);
}
