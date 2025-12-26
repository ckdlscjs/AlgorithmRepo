#include <bits/stdc++.h>

using namespace std;
// 1.이모티콘 플러스 가입자를 최대한늘린다
// 2.판매액을늘린다
// 1>2
vector<int> answer(2, 0);
const int percent[] = {10, 20, 30, 40};
void Check(const std::vector<std::vector<int>>& users, const std::vector<int>& emos, int* arr, int idx)
{
    if(idx >= emos.size())
    {
        std::vector<int> results(2, 0);
        
        for(const auto& iter : users)
        {
            int sum = 0;
            for(int i = 0; i < emos.size(); i++)
            {
                if(arr[i] >= iter[0])
                    sum += emos[i] - emos[i] * arr[i] / 100;
            }
            if(sum >= iter[1])
                results[0] += 1;
            else
                results[1] += sum;
        }
        if(results[0] > answer[0])
        {
            answer[0] = results[0];
            answer[1] = results[1];
        }
        else if(results[0] == answer[0] && results[1] > answer[1])
            answer[1] = results[1];
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        arr[idx] = percent[i];
        Check(users, emos, arr, idx+1);
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) 
{
    int arr[10];
    Check(users, emoticons, arr, 0);
    return answer;
}