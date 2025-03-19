#include <bits/stdc++.h>
int T;
std::string str;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    for(int t = 0; t < T; t++)
    {
        std::cin >> str;
        std::vector<int> alps(26, 0);
        int idx = 0;
        while(idx < str.size())
        {
            int alp = str[idx] - 'A';
            alps[alp]++;
            if(alps[alp] % 3 == 0)
            {
                if(idx + 1 == str.size() || str[idx+1] != str[idx]) break;
                idx += 2;
            }
            else
                idx++;
        }
        std::cout << (idx == str.size() ? "OK" : "FAKE")  << '\n';
    }
	return 0;
}