#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) 
{
    std::vector<std::vector<int>> answer;
    int idx_ext = ext == "code" ? 0 : ext == "date" ? 1 : ext == "maximum" ? 2 : 3;
    int idx_sort = sort_by == "code" ? 0 : sort_by == "date" ? 1 : sort_by == "maximum" ? 2 : 3;
    for(const auto& iter : data)
    {
        if(iter[idx_ext] > val_ext)
            continue;
        answer.push_back(iter);
    }
    std::sort(answer.begin(), answer.end(), 
              [&](const std::vector<int>& a, const std::vector<int>& b)
              {
                  return a[idx_sort] < b[idx_sort];
              }
             );
    return answer;
}