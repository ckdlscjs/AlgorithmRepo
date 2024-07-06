#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
{
    vector<vector<int>> answer;
    for(int i = 0; i < arr1.size(); i++)
    {   
        std::vector<int> i_result;
        for(int idx = 0; idx < arr2[0].size(); idx++)
        {
            int sum = 0;
            for(int j = 0; j < arr1[i].size(); j++)
            {
                sum += arr1[i][j] * arr2[j][idx];
            }
            i_result.push_back(sum);
        }
        answer.push_back(i_result);
    }
    return answer;
}