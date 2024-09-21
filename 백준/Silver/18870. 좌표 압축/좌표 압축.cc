#include <bits/stdc++.h>
std::map<int, int> nums;
const int MaxN = 1000005;
int arr[MaxN];
int n = 0;
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
        nums[arr[i]] = 0;
    }
    int cnt = 0;
    for(auto& iter : nums)
    {
        nums[iter.first] = cnt++;
    }
    for(int i = 0; i < n; i++)
    {
        std::cout << nums[arr[i]] << ' ';
    }
    return 0;
}