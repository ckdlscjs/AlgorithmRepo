#include <string>
#include <vector>

using namespace std;

int check(const std::vector<int>& nums, int target, int idx, int sum)
{
    int ret = 0;
    if(idx >= nums.size())
        return sum == target ? 1 : 0;
    ret += check(nums, target, idx+1, sum + nums[idx]);
    ret += check(nums, target, idx+1, sum - nums[idx]);
    return ret;
}
int solution(vector<int> numbers, int target) 
{
    return check(numbers, target, 0, 0);
}