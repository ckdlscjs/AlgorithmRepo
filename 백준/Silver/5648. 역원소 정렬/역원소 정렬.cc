#include <bits/stdc++.h>
using namespace std;
int N;
std::string str;
std::vector<long long> nums;
void QuickSort(int s, int e)
{
    if(s >= e) return;
    long long pivot = nums[s];
    std::vector<long long> arr_l;
    std::vector<long long> arr_r;
    for(int i = s+1; i <= e; i++)
    {
        if(nums[i] <= pivot) arr_l.push_back(nums[i]);
        else arr_r.push_back(nums[i]);
    }
    int idx = s;
    for(const auto& iter : arr_l) nums[idx++] = iter;
    nums[idx] = pivot;
    pivot = idx++;
    for(const auto& iter : arr_r) nums[idx++] = iter;
    QuickSort(s, pivot-1);
    QuickSort(pivot+1, e);
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++)
    {
        std::cin >> str;
        long long num = 0;
        for(auto iter = str.rbegin(); iter != str.rend(); iter++)
        {
            num *= 10LL;
            num += (long long)(*iter-'0');
        }
        nums.push_back(num);
    }
    QuickSort(0, N-1);
    for(const auto& iter : nums)
        std::cout << iter << '\n';
    return 0;
}
