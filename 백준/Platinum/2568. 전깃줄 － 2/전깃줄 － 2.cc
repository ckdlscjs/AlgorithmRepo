#include <bits/stdc++.h>
using namespace std;
int N, A, B, lis[100'005], idx[100'005], len;
std::pair<int, int> inputs[100'005];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++) std::cin >> inputs[n].first >> inputs[n].second;
    std::sort(inputs, inputs + N);
    for(int i = 0; i < N; i++)
    {
        if(len == 0 || lis[len-1] < inputs[i].second)
        {
            idx[i] = len;
            lis[len++] = inputs[i].second;
        }
        else
        {
            int lo = -1, hi = len;
            while(lo + 1 < hi)
            {
                int mid = (lo + hi) / 2;
                if(inputs[i].second <= lis[mid]) hi = mid;
                else lo = mid;
            }
            idx[i] = hi;
            lis[hi] = inputs[i].second;
        }
    }
    std::cout << N - len-- << '\n';
    std::stack<int> st;
    for(int i = N-1; i >= 0; i--)
    {
        if(idx[i] == len) len--;
        else st.push(inputs[i].first);
    }
    while(st.size())
    {
        std::cout << st.top() << '\n';
        st.pop();
    }
    
    return 0;
}
