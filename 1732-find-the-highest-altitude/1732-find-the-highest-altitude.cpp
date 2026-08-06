auto fastio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();
class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        std::vector<int> psums(gain.size() + 1, 0);
        int ret = 0;
        for(int i = 0; i < gain.size(); i++)
        {
           psums[i+1] = psums[i] + gain[i];
           ret = std::max(ret, psums[i+1]);
        }
        return ret;
    }
};