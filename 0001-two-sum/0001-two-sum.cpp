class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        std::vector<std::pair<int, int>> arr;
        for(int i = 0; i < nums.size(); i++)
            arr.push_back({nums[i], i});
        std::stable_sort(arr.begin(), arr.end());
        int l = 0, r = nums.size() - 1;
        while(l < r && arr[l].first + arr[r].first != target)
        {
            if(arr[l].first + arr[r].first > target) r--;
            else l++;
        }
        return {arr[l].second, arr[r].second};
    }
};