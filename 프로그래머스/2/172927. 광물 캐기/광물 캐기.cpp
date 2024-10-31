//https://school.programmers.co.kr/learn/courses/30/lessons/172927
#include <bits/stdc++.h>
using namespace std;
std::unordered_map<std::string, int> idxs;
int arr[5][5];
int res = INT_MAX;
void Check(std::vector<int>& picks, const std::vector<std::string>& minerals, int idx, int sum)
{
    if(idx >= minerals.size() || (picks[0] | picks[1] | picks[2]) == 0)
    {
        res = std::min(res, sum);
        return;
    }
    for(int i = 0; i < 3; i++)
    {
        if(picks[i])
        {
            picks[i] -= 1;
            int j = idx;
            int temp = 0;
            for(j; j < idx + 5 && j < minerals.size(); j++)
                temp += arr[i][idxs[minerals[j]]];
            Check(picks, minerals, j, sum + temp);
            picks[i] += 1;
        }
    }
}
int solution(vector<int> picks, vector<string> minerals) 
{
    idxs["diamond"] = 0; idxs["iron"] = 1; idxs["stone"] = 2;
    arr[0][0] = arr[0][1] = arr[0][2] = arr[1][1] = arr[1][2] = arr[2][2] = 1;
    arr[1][0] = arr[2][1] = 5;
    arr[2][0] = 25;
    Check(picks, minerals, 0, 0);
    std::cout << res;
    return res;
}