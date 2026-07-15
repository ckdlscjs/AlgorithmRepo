auto fastio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();

class Solution 
{
public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        std::vector<int> ret(nums.size() * 2, 0);
        std::memcpy(ret.data(), nums.data(), nums.size() * sizeof(int));
        std::memcpy(ret.data() + nums.size(), nums.data(), nums.size() * sizeof(int));
        return ret;
    }
};