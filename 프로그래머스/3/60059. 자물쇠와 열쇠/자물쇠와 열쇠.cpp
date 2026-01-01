#include <bits/stdc++.h>

using namespace std;

void RotateCW(std::vector<std::vector<int>>& arr)
{
    std::vector<std::vector<int>> temp(arr.size(), std::vector<int>(arr[0].size(), 0));
    for(int i = 0; i < arr.size(); i++)
        for(int j = 0; j < arr[i].size(); j++)
            temp[i][j] = arr[arr.size() - 1 - j][i];
    for(int i = 0; i < arr.size(); i++)
        for(int j = 0; j < arr[i].size(); j++)
            arr[i][j] = temp[i][j];
}
bool Check(const std::vector<std::vector<int>>& key, const std::vector<std::vector<int>>& lock)
{
    int n = lock.size();
    for(int i = -n; i < n; i++)
    {
        for(int j = -n; j < n; j++)
        {
            int cnt = 0;
            for(int ii = 0; ii < lock.size(); ii++)
            {
                for(int jj = 0; jj < lock[0].size(); jj++)
                {
                    int ny = i + ii;
                    int nx = j + jj;
                    if(ny < 0 || nx < 0 || ny >= key.size() || nx >= key[0].size())
                    {
                        if(!lock[ii][jj]) 
                            break;
                    }
                    else
                    {
                        if(lock[ii][jj] && key[ny][nx])
                            break;
                        if(!lock[ii][jj] && !key[ny][nx])
                            break;
                    }
                    cnt++;
                }
            }
            if(cnt >= lock.size() * lock[0].size())
                return true;
        }
    }
    return false;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) 
{ 
    for(int i = 0; i < 4; i++)
    {
        RotateCW(key);
        if(Check(key, lock))
            return true;
    }
    return false;
}