#include <bits/stdc++.h>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::string str;
    std::cin >> str;
    std::set<std::string> suffix;
    for(int i = 0; i < str.size(); i++) suffix.insert(str.substr(i));
    for(const auto& iter : suffix) std::cout << iter << '\n';
    return 0;
}