#include <bits/stdc++.h>
using namespace std;
int N, M, L;
std::vector<int> arr;
bool Check(int mid)
{
    int cnt = 0;
    for(int i = 1; i < arr.size(); i++)
    {
        int dist = arr[i] - arr[i-1];
        cnt += dist/mid;
        if(dist % mid == 0) cnt--;
    }
    return cnt <= M;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N >> M >> L;
    arr.resize(N);
    for(int n = 0; n < N; n++) std::cin >> arr[n];
    arr.push_back(0);
    arr.push_back(L);
    std::sort(arr.begin(), arr.end());
    
    int lo = 0, hi = L;
    while(lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;
        if(Check(mid)) hi = mid;
        else lo = mid;
    }
    std::cout << hi;
    return 0;
}
