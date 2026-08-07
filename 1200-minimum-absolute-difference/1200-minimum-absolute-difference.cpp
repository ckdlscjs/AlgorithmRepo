class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {
        std::sort(arr.begin(), arr.end());
        std::map<int, vector<vector<int>>> mp;
        for(int i = 0; i < arr.size()-1; i++)
            mp[arr[i+1] - arr[i]].push_back({arr[i], arr[i+1]});
        return mp.begin()->second;
    }
};