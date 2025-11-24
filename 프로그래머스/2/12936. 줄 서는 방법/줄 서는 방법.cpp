#include <bits/stdc++.h>

using namespace std;
long long perm(int n)
{
    if(n <= 1) return 1;
    return n * perm(n-1);
}
vector<int> solution(int n, long long k) 
{
    std::vector<int> arr, ans;
    for(int i = 1; i <= n; i++) arr.push_back(i);
    std::function<void(std::vector<int>&, std::vector<int>&, long long)> func =
    [&](std::vector<int>& arr, std::vector<int>& ans, long long cnt){
        if(arr.size() <= 1)
        {
            ans.push_back(arr[0]);
            return;
        }
        long long p = perm(arr.size()-1);
        for(long long i = 1; i <= arr.size(); i++)
        {
            if(i * p >= cnt)
            {
                ans.push_back(arr[i-1]);
                arr.erase(arr.begin() + i - 1);
                func(arr, ans, cnt - (i - 1) * p);
                return;
            }
        }
    };
    func(arr, ans, k);
    return ans;
}