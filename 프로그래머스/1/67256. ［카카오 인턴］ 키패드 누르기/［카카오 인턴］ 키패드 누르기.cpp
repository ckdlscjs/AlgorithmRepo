#include <bits/stdc++.h>

using namespace std;
std::vector<std::pair<int, int>> nums;
std::pair<int, int> hand_left;
std::pair<int, int> hand_right;
string solution(vector<int> numbers, string hand) 
{
    nums.push_back({3, 1}); //0
    nums.push_back({0, 0}); //1
    nums.push_back({0, 1}); //2
    nums.push_back({0, 2}); //3
    nums.push_back({1, 0}); //4
    nums.push_back({1, 1}); //5
    nums.push_back({1, 2}); //6
    nums.push_back({2, 0}); //7
    nums.push_back({2, 1}); //8
    nums.push_back({2, 2}); //9
    nums.push_back({3, 0}); //*
    nums.push_back({3, 2}); //#
    
    string answer = "";
    hand_left = nums[10];
    hand_right = nums[11];
    
    for(const int& num : numbers)
    {
        switch(num)
        {
            case 1 : case 4 : case 7 :
                {
                    hand_left = nums[num];
                    answer += 'L';
                }break;
            
            case 2 : case 5 : case 8 : case 0:
                {
                    int dist_left = std::abs(hand_left.first - nums[num].first) + std::abs(hand_left.second - nums[num].second);
                    int dist_right = std::abs(hand_right.first - nums[num].first) + std::abs(hand_right.second - nums[num].second);
                    bool use_left = dist_left == dist_right ? (hand == "left" ? true : false) : dist_left < dist_right ? true : false;
                    if(use_left)
                    {
                        hand_left = nums[num];
                        answer += 'L';
                    }
                    else
                    {
                        hand_right = nums[num];
                        answer += 'R';
                    }
                }break;
            
            case 3 : case 6 : case 9:
                {
                    hand_right = nums[num];
                    answer += 'R';
                }break;
        }
    }
    return answer;
}