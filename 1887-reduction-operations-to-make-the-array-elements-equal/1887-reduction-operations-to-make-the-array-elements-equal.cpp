class Solution {
public:
    int reductionOperations(vector<int>& nums) 
    {
        std::map<int, int> mp;
        for(const auto& iter : nums)
            mp[iter] = 0;

        int cur = mp.begin()->first;
        int cnt = 0;
        for(auto& iter : mp)
        {
            if(iter.first != cur)
            {
                cnt++;
                cur = iter.first;
            }
            iter.second = cnt;
        }
        int ret = 0;
        for(const auto& iter : nums)
            ret += mp[iter];
        return ret;
    }
};