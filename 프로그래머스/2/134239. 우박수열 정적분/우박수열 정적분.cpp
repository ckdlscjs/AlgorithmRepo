#include <bits/stdc++.h>

using namespace std;
//콜라츠추측, k를 기준으로 1로 만드는 x/y 값을구한다 0~n
//결과값을 정적분한다, x에대한 a~b가 주어지면 a,b, y=0의 공간의면적이 정적분

vector<double> solution(int k, vector<vector<int>> ranges) 
{
    std::vector<int> collaz;
    collaz.push_back(k);
    while(k != 1)
    {
        if(k % 2 == 0) k = k / 2;
        else k = k * 3 + 1;
        collaz.push_back(k);
    }
    std::vector<double> psums(collaz.size());
    for(int i = 1; i < collaz.size(); i++)
    {
        psums[i] = std::abs(collaz[i] - collaz[i-1]) * 0.5f + (double)std::min(collaz[i], collaz[i-1]);
        std::cout << psums[i] << ' ';
        psums[i] += psums[i-1];
    }
    vector<double> answer;
    for(const auto& iter : ranges)
    {
        int a = iter[0];
        int b = collaz.size() - 1 - (-iter[1]);
        if(a > b) answer.push_back(-1);
        else answer.push_back(psums[b] - psums[a]);
    }
    
    return answer;
}