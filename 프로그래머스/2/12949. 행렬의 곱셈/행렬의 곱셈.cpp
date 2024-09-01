#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
{
    vector<vector<int>> answer(arr1.size(), std::vector<int> (arr2[0].size(), 0));
    for(int i = 0; i < arr1.size(); i++)
    {
        for(int j = 0; j < arr2[0].size(); j++)
        {
            for(int idx = 0; idx < arr1[0].size(); idx++)
            {
                answer[i][j] += (arr1[i][idx] * arr2[idx][j]);
            }
        }
    }
    return answer;
}