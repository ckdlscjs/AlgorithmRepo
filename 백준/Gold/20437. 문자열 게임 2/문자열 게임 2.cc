#include <bits/stdc++.h>
int T, K;
std::string W;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    for(int t = 0; t < T; t++)
    {
        std::cin >> W >> K;
        int min_max[2] = {W.size(), 0};
        std::vector<int> alp[26];
        for(int i = 0; i < W.size(); i++) alp[W[i]-'a'].push_back(i); //알파벳을 기준으로 인덱스 저장
        for(int i = 0; i < 26; i++)
        {
            if(alp[i].size() < K) continue;
            
            int st = 0, en = K-1;
            while(en < alp[i].size())
            {
                min_max[0] = std::min(min_max[0], alp[i][en] - alp[i][st] + 1);
                min_max[1] = std::max(min_max[1], alp[i][en] - alp[i][st] + 1);
                st++;
                en++;
            }
        }
        if(min_max[0] == W.size() && min_max[1] == 0)
            std::cout << -1 << '\n';
        else
            std::cout << min_max[0] << ' ' << min_max[1] << '\n';
    }
	return 0;
}