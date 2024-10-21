//https://school.programmers.co.kr/learn/courses/30/lessons/60059
#include <bits/stdc++.h>
using namespace std;
std::vector<std::vector<int>> RotateKey(vector<vector<int>>& key)
{
    std::vector<std::vector<int>> ret(key.size(), std::vector<int>(key.size(), 0));
    for(int i = 0; i < key.size(); i++)
        for(int j = 0; j < key[i].size(); j++)
            ret[j][key.size() - 1 - i] = key[i][j];
    return ret;
}
bool Check(const vector<vector<int>>& key, const int& y, const int& x, vector<vector<int>> lock)
{
    for(int i = 0; i < key.size(); i++)
        for(int j = 0; j < key.size(); j++)
            lock[y + i][x + j] += key[i][j];
    
    for(int i = 0; i < lock.size() - key.size() * 2; i++)
        for(int j = 0; j < lock.size() - key.size() * 2; j++)
            if(lock[key.size() + i][key.size() + j] != 1) 
                return false;
    return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) 
{
    int b = lock.size() + key.size() * 2;
    std::vector<std::vector<int>> arr(b, std::vector<int>(b, 0));
    
    for(int i = 0; i < lock.size(); i++)
        for(int j = 0; j < lock.size(); j++)
            arr[key.size() + i][key.size() + j] = lock[i][j];
    
    for(int r = 0; r < 4; r++)
    {
        for(int offset_i = 0; offset_i < b - key.size(); offset_i++)
            for(int offset_j = 0; offset_j < b - key.size(); offset_j++)
                if(Check(key, offset_i, offset_j, arr))
                    return true;
        key = RotateKey(key);
    }
    
    return false;
}