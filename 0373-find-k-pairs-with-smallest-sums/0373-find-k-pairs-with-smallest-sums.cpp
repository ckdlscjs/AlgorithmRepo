auto fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();
#define tiii std::tuple<int, int, int>
class Solution 
{
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        std::priority_queue<tiii, std::vector<tiii>, std::greater<tiii>> pq;
        int smallest = std::min(k, (int)(nums1.size()));
        for(int i = 0; i < smallest; i++)
        {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        std::vector<std::vector<int>> ret;
        int i = 1;
        while(k)
        {
            k--;
            auto iter = pq.top(); pq.pop();
            int idx1 = std::get<1>(iter);
            int idx2 = std::get<2>(iter);
            ret.push_back({nums1[idx1], nums2[idx2]});
            if(idx2+1 < nums2.size())
            {
                pq.push({nums1[idx1] + nums2[idx2+1], idx1, idx2+1});
            }
        }
        return ret;
    }
};