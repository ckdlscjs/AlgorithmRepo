#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) 
{
    std::sort(data.begin(), data.end(), [&](const std::vector<int>& a, const std::vector<int>& b)->bool{
        return a[col-1] == b[col-1] ? a[0] > b[0] : a[col-1] < b[col-1];
    });
    /*
    for(const auto& iter : data)
    {
        for(const auto& it : iter)
            std::cout << it << ' ';
        std::cout << '\n';
    }
    */
    int answer = 0;
    
    for(int i = row_begin; i <= row_end; i++)
    {
        int s_i = 0;
        for(const auto& iter : data[i-1])
            s_i += iter % i;
        //std::cout << s_i << '\n';
        answer ^= s_i;
    }
    return answer;
}