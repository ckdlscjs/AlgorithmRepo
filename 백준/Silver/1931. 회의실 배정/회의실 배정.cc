#include <bits/stdc++.h>
int n;
std::vector<std::pair<int, int>> confs;
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        confs.push_back({a, b});
    }
    std::sort(confs.begin(), confs.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b){
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    });
    int ans = 1;
    int r = confs[0].second;
    for(int i = 1; i < confs.size(); i++)
    {
        if(r <= confs[i].first)
        {
            r = confs[i].second;
            ans++;
        }
    }
    std::cout << ans;
    return 0;
}