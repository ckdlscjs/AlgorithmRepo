#include <bits/stdc++.h>
using namespace std;
int N, in[100'005], po[100'005], inidx[100'005];
void PreOrder(int st_in, int en_in, int st_po, int en_po)
{
    if(st_in > en_in || st_po > en_po) return;
    std::cout << po[en_po] << ' ';
    int root_idx = inidx[po[en_po]];
    int size_left = root_idx - st_in;
    int size_right = en_in - root_idx;
    PreOrder(st_in, root_idx-1, st_po, st_po + size_left - 1);
    PreOrder(root_idx + 1, en_in, en_po - size_right, en_po - 1);
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    for(int n = 1; n <= N; n++)
    {
        std::cin >> in[n];
        inidx[in[n]] = n;
    }
    for(int n = 1; n <= N; n++)
    {
        std::cin >> po[n];
    }
    PreOrder(1, N, 1, N);
    return 0;
}
