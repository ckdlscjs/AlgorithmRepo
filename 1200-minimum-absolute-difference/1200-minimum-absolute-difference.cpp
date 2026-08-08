class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {
        vector<vector<int>> ret;
        std::sort(arr.begin(), arr.end());
        int diff_min = 1e7;
        for(int i = 0; i < arr.size()-1; i++)
            diff_min = std::min(diff_min, arr[i+1] - arr[i]);
        for(int i = 0; i < arr.size()-1; i++)
            if(diff_min == arr[i+1] - arr[i])
                ret.push_back({arr[i], arr[i+1]});
        return ret;
    }
};