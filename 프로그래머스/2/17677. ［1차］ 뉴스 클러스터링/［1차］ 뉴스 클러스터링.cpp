#include <bits/stdc++.h>
using namespace std;
std::unordered_map<std::string, std::pair<int, int>> chks;
int solution(string str1, string str2) 
{
    //std::cout << conv2;
    for(int i = 0; i < str1.size()-1; i++)
    {
        std::string temp = str1.substr(i, 2);
        if(!std::isalpha(temp[0]) || !std::isalpha(temp[1]))
            continue;
        if(temp[0] <= 'Z') temp[0] += 32;
        if(temp[1] <= 'Z') temp[1] += 32;
        chks[temp].first++;
    }
    for(int i = 0; i < str2.size()-1; i++)
    {
        std::string temp = str2.substr(i, 2);
        if(!std::isalpha(temp[0]) || !std::isalpha(temp[1]))
            continue;
        if(temp[0] <= 'Z') temp[0] += 32;
        if(temp[1] <= 'Z') temp[1] += 32;
        chks[temp].second++;
    }
    int cnt_intersect = 0, cnt_union = 0;
    for(const auto& iter : chks)
    {
        cnt_intersect += std::min(iter.second.first, iter.second.second);
        cnt_union += std::max(iter.second.first, iter.second.second);
    }
    //std::cout << cnt_intersect << ' ' << cnt_union;
    if(cnt_intersect == cnt_union) return 65'536;
    //cnt_intersect = std::max(cnt_intersect, 1);
    cnt_union = std::max(cnt_union, 1);
    return (int)((float)cnt_intersect / (float)cnt_union * 65'536) ;
}