class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int arr[20'001];
        std::fill_n(&arr[0], 20'001, 0);
        for(const auto& iter : nums)
            arr[iter + 10'000]++;
        int s = 20'000;
        while(s >= 0 && k > 0)
        {
            if(arr[s])
            {
                //std::cout << s << ' ' << arr[s] << '\n';
                k -= arr[s];
                if(k <= 0) break;
            }
             s--;
        }
        return s - 10'000;
    }
};