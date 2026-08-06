class Solution {
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        long long sum_all = 0;
        for(const auto& iter : nums)
            sum_all += iter;
        int R = sum_all % p;
        if(R <= 0) return 0;

        std::unordered_map<int, int> u_d;
        u_d[0] = -1;
        long long sum_cur = 0;
        int ret = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            sum_cur += nums[i];
            int R1 = sum_cur % p;
            int R2 = (R1 - R + p) % p;
            if(u_d.count(R2))
                ret = std::min(ret, i - u_d[R2]);
            u_d[R1] = i;
        }
        return ret < nums.size() ? ret : -1;
    }
};