#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> files) 
{
    std::stable_sort(files.begin(), files.end(), [](const std::string& a, const std::string& b) {
        std::function<std::vector<std::string>(const std::string& str)> func = [](const std::string& str)
        {
            std::vector<std::string> HNT(3, "");
            int idx = 0;
            for(const auto& iter : str)
            {
                if(idx == 0 && std::isdigit(iter)) idx++;
                if(idx == 1 && !std::isdigit(iter)) idx++;
                if('A' <= iter && iter <= 'Z') HNT[idx] += std::string(1, iter + 32);
                else HNT[idx] += iter;
            }
            return HNT;
        };
        //std::cout << a << b <<'\n';
        auto hnt_a = func(a);
        auto hnt_b = func(b);
        if(hnt_a[0] == hnt_b[0])
        {
            return std::stoi(hnt_a[1]) < std::stoi(hnt_b[1]);
        }
        return hnt_a[0] < hnt_b[0];
    });
    
    return files;
}