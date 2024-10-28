//https://school.programmers.co.kr/learn/courses/30/lessons/1845
#include <bits/stdc++.h>
using namespace std;
std::unordered_set<int> sets;
int solution(vector<int> nums)
{
    for(const int& num : nums) sets.insert(num);
    return sets.size() > nums.size() / 2 ? nums.size() / 2 : sets.size();
}