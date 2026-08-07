class Solution {
public:
    int waysToMakeFair(vector<int>& nums) 
    {
        std::vector<int> odds(nums.size()+1, 0), evens(nums.size()+1, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            odds[i+1] = odds[i];
            evens[i+1] = evens[i];
            if(i % 2 == 0) odds[i+1] += nums[i];
            else evens[i+1] += nums[i];
            //std::cout << odds[i+1] << ' ' << evens[i+1] << '\n';
        }
        int ret = 0;
        for(int i = 1; i <= nums.size(); i++)
        {
            long long sum_odds = 0, sum_evens = 0;
            if(i % 2)
            {
                if(i-2 >= 0)
                    sum_odds += odds[i-2];
                sum_odds += evens[nums.size()] - evens[i];

                if(i - 1 >= 0)
                    sum_evens += evens[i-1];
                sum_evens += odds[nums.size()] - odds[i];
            }
            else
            {
                if(i-1 >= 0)
                    sum_odds += odds[i-1];
                sum_odds += evens[nums.size()] - evens[i];

                if(i-2 >= 0)
                    sum_evens += evens[i-2];
                sum_evens += odds[nums.size()] - odds[i];
            }
            //std::cout << i-1 << ' ' <<  sum_odds << ' ' <<  sum_evens << '\n';
            if(sum_odds == sum_evens)
                ret++;
        }
        return ret;
    }
};