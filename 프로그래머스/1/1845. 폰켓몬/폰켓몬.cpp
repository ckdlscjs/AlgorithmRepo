#include <bits/stdc++.h>
using namespace std;
std::set<int> sets;
int solution(vector<int> nums)
{
    for(const int& num : nums)
        sets.insert(num);
    
    return sets.size() > nums.size() / 2 ? nums.size() / 2 : sets.size();
}