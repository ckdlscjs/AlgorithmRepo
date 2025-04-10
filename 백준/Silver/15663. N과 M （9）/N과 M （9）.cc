#include <bits/stdc++.h>
using namespace std;
int N, M, nums[10], ans[10];
bool chk[10];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N >> M;
    for(int n = 0; n < N; n++) std::cin >> nums[n];
    std::sort(nums, nums + N);
    std::function<void(int, int)> func = [&](int cnt, int idx) -> void 
    {
        if(cnt >= M)
        {
            for(int i = 0; i < M; i++) std::cout << ans[i] << ' ';
            std::cout << '\n';
            return;
        }
        int cur = -1;
        for(int i = 0; i < N; i++)
        {
            if(nums[i] == cur || chk[i]) continue;
            chk[i] = true;
            cur = nums[i];
            ans[cnt] = nums[i];
            func(cnt + 1, i + 1);
            chk[i] = false;
        }
    };
    func(0, 0);
    return 0;
}
