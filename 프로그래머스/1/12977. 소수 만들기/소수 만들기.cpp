#include <vector>
#include <iostream>
using namespace std;
bool NotPrime[3030];
int solution(vector<int> nums) {
    int answer = 0;
    for(int i = 2; i < 3030; i++)
    {
        if(NotPrime[i])
            continue;
        for(int j = i + i; j < 3030; j += i)
            NotPrime[j] = true;
    }
    
    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = i + 1; j < nums.size(); j++)
        {
            for(int k = j + 1; k < nums.size(); k++)
            {
                if(!NotPrime[nums[i] + nums[j] + nums[k]])
                    answer++;
            }
        }
    }

    return answer;
}