#include <bits/stdc++.h>
using namespace std;
int arr[55][55];
int solution(vector<int> mats, vector<vector<string>> park) 
{
    int answer = 0;
    int maxVal = 0;
    for(int i = 0; i < park.size(); i++)
    {
        for(int j = 0; j < park[i].size(); j++)
        {
            arr[i+1][j+1] = park[i][j] != "-1" ? 0 : std::min({arr[i][j+1], arr[i+1][j], arr[i][j]}) + 1;
            maxVal = std::max(maxVal, arr[i+1][j+1]);
        }
    }
    std::sort(mats.begin(), mats.end(), std::greater<>());
    for(const auto& iter : mats)
    {
        if(iter > maxVal)
            continue;
        answer = iter;
        break;
    }
    return answer == 0 ? -1 : answer;
}