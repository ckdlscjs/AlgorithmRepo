#include <bits/stdc++.h>
using namespace std;
std::vector<std::string> croatais;
int cnt;
std::string str;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    croatais.push_back("dz=");
    croatais.push_back("c=");
    croatais.push_back("c-");
    croatais.push_back("d-"); 
    croatais.push_back("lj");
    croatais.push_back("nj");
    croatais.push_back("s=");
    croatais.push_back("z=");
    std::cin >> str;
    for(const auto& iter : croatais)
    {
        while(str.find(iter) != std::string::npos)
        {
            cnt++;
            int idx = str.find(iter);
            for(int i = 0; i < iter.size(); i++)
                str[idx+i] = '.';
            //std::cout << str << '\n';
        }
    }
    for(const auto& iter : str)
        if(std::isalpha(iter))
            cnt++;
    std::cout << cnt;
    return 0;
}