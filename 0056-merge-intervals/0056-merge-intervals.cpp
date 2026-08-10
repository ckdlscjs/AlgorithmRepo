class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        std::vector<std::vector<int>> ret;
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b){
            return a[0] == b[0] ? (a[1] < b[1]) : (a[0] < b[0]);
        });
        int s = intervals[0][0], e = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++)
        {
            const auto& iter = intervals[i];
            if(e >= iter[0])
            {
                e = std::max(e, iter[1]);
            }
            else
            {
                ret.push_back({s, e});
                s = iter[0];
                e = iter[1];
            }
        }
        ret.push_back({s, e});
        return ret;
    }

};