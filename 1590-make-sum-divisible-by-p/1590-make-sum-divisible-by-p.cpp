class Solution {
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        long long allSum = 0;
        for(const auto& iter : nums)
            allSum += iter;
        int R = allSum % p;
        if(R == 0) return 0;
        std::map<int, int> index;
        index[0] = -1;
        long long curSum = 0;
        int minLen = nums.size();
        for(int j = 0; j < nums.size(); j++)
        {
            curSum += nums[j];
            int curMod = curSum % p;
            int X = (curMod - R + p) % p;
            if(index.count(X))
                minLen = std::min(minLen, j - index[X]);
            index[curMod] = j;
        }
        return minLen < nums.size() ? minLen : -1;
    }
};