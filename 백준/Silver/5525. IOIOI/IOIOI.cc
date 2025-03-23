#include <bits/stdc++.h>
int N, M;
std::string pattern, S;
std::vector<int> MakeTable()
{
    std::vector<int> table(pattern.size());
    int j = 0;
    for(int i = 1; i < pattern.size(); i++)
    {
        while(j > 0 && pattern[i] != pattern[j])
            j = table[j-1];
        if(pattern[j] == pattern[i])
            table[i] = ++j;
    }
    return table;
}
int KMP()
{
    std::vector<int> table = MakeTable();
    int ret = 0, j = 0;
    for(int i = 0; i < S.size(); i++)
    {
        while(j > 0 && pattern[j] != S[i]) j = table[j-1];
        if(pattern[j] == S[i])
        {
            if(j >= pattern.size()-1)
            {
                ret++;
                j = table[j];
            }
            else
            {
                j++;
            }
        }
    }
    return ret;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> S;
    pattern = "I";
    for(int i = 0; i < N; i++) pattern += "OI";
    std::cout << KMP();
	return 0;
}