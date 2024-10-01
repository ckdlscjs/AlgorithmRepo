#include <bits/stdc++.h>
using namespace std;
std::unordered_map<std::string, int> idxs;
vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) 
{
    idxs["code"] = 0;
    idxs["date"] = 1;
    idxs["maximum"] = 2;
    idxs["remain"] = 3;
    for(auto iter = data.begin(); iter != data.end();)
    {
        if((*iter)[idxs[ext]] > val_ext)
            iter = data.erase(iter);
        else
            iter++;
    }
    std::sort(data.begin(), data.end(), [=](const std::vector<int>& a, const std::vector<int>& b){
        return a[idxs[sort_by]] < b[idxs[sort_by]];
    });
    
    return data;
}