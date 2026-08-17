class Solution {
    void MergeSort(std::vector<int>& arr, int s, int e)
    {
        if(s >= e) return;
        int mid = (s + e) / 2;
        MergeSort(arr, s, mid);
        MergeSort(arr, mid+1, e);
        std::vector<int> temp;
        int sl = s, sr = mid+1;
        while(sl <= mid && sr <= e)
            temp.push_back(arr[sl] <= arr[sr] ? arr[sl++] : arr[sr++]);
        while(sl <= mid)
            temp.push_back(arr[sl++]);
        while(sr <= e)
            temp.push_back(arr[sr++]);
        for(const auto& iter : temp)
            arr[s++] = iter;
    }
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        MergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};