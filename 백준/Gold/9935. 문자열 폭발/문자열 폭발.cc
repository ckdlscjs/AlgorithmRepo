#include <bits/stdc++.h>
std::string str;
std::string fi;
std::string st;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> str >> fi;
    int cont_cnt = 0;
    for(const auto& iter : str)
    {
      st += iter;
      if(st.size() >= fi.size() && st.substr(st.size() - fi.size(), fi.size()) == fi)
        st.erase(st.size() - fi.size(), fi.size());
    }
    std::cout << (st.empty() ? "FRULA" : st);
    return 0;
}