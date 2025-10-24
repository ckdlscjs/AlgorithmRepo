#include <bits/stdc++.h>
using namespace std;
//10'000 <= n 갯수, 자연수n개 1...
//s -> 합
//리스트의 원소는 중복을 허용한다, 오름차순
vector<int> solution(int n, int s) 
{
    if(n > s)
        return {-1};
    int mid = s / n;
    int mod = s % n;
    std::vector<int> answer(n, mid);
    for(int i = answer.size()-1; mod && i >= 0; i--)
    {
        answer[i]++;
        mod--;
    }
    
    return answer;
}