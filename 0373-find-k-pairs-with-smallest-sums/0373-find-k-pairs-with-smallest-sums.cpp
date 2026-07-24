auto fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
};
#define tiii std::tuple<int, int, int>
struct Entity
{
    int sum;
    int idx1;
    int idx2;
};
struct comp
{
    bool operator()(const Entity& e1, const Entity& e2)
    {
        return e1.sum > e2.sum;
    }
};
class Solution 
{
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        std::priority_queue<Entity, std::vector<Entity>, comp> pq;
        int smallest = std::min(nums1.size(), nums2.size());
        for(int i = 0; i < nums1.size(); i++)
        {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        std::vector<std::vector<int>> ret;
        int i = 1;
        while(k && !pq.empty())
        {
            k--;
            auto iter = pq.top(); pq.pop();
            int idx1 = iter.idx1;
            int idx2 = iter.idx2;
            ret.push_back({nums1[idx1], nums2[idx2]});
            if(idx2+1 < nums2.size())
            {
                pq.push({nums1[idx1] + nums2[idx2+1], idx1, idx2+1});
            }
        }
        return ret;
    }
};