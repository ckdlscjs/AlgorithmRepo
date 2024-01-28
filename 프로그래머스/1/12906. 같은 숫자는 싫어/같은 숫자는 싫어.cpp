#include <bits/stdc++.h>
using namespace std;
std::unordered_set<int> sets;
vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);
    for(const int& num : arr)
    {
        if(answer[answer.size()-1] == num)
            continue;
        answer.push_back(num);
    }

    return answer;
}