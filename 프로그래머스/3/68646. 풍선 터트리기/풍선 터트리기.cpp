#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> a) 
{
    std::vector<int> a_left(a);
    std::vector<int> a_right(a);
    int minVal = a[0];
    for(int i = 0; i < a.size(); i++)
    {
        minVal = std::min(minVal, a[i]);
        a_left[i] = minVal;
    }
    minVal = a.back();
    for(int i = a.size()-1; i >= 0; i--)
    {
        minVal = std::min(minVal, a[i]);
        a_right[i] = minVal;
    }
    int answer = 2;
    for(int i = 1; i < a.size() - 1; i++)
    {
        if(a_left[i] < a[i] && a_right[i] < a[i]) continue;
        answer++;
    }
    return answer;
}