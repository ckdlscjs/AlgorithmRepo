#include <bits/stdc++.h>
int N, idx1, idx2;
std::vector<std::string> channels;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++)
    {
        std::string str;
        std::cin >> str;
        channels.push_back(str);
        if(str == "KBS1") idx1 = n;
        else if(str == "KBS2") idx2 = n;
    }
    for(int i = 0; i < idx1; i++) std::cout << 1;
    for(int i = 0; i < idx1; i++) std::cout << 4;
    if(idx1 > idx2) idx2++;
    for(int i = 0; i < idx2; i++) std::cout << 1;
    for(int i = 0; i < idx2-1; i++) std::cout << 4;
    return 0;
}