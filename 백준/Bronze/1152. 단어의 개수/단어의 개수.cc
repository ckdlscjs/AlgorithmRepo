#include <bits/stdc++.h>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int cnt = 1;
    std::string str;
    std::getline(std::cin, str, '\n');
    for(int i = 1; i < str.size()-1; i++)
        if(str[i] == ' ')
            cnt++;
    if(str.size() <= 1 && str[0] == ' ')
        std::cout << 0;
    else
        std::cout << cnt;
    return 0;
}