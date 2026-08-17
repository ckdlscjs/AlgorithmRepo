auto fastio = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
    void MergeSort(std::vector<int>& arr, std::vector<int>& temp, int s, int e)
    {
        if(s >= e) return;
        int mid = (s + e) / 2;
        MergeSort(arr, temp, s, mid);
        MergeSort(arr, temp, mid+1, e);
        int sl = s, sr = mid+1, idx = s;
        while(sl <= mid && sr <= e)
            temp[idx++] = arr[sl] <= arr[sr] ? arr[sl++] : arr[sr++];
        while(sl <= mid)
            temp[idx++] = arr[sl++];
        while(sr <= e)
            temp[idx++] = arr[sr++];
        for(s; s <= e; s++)
            arr[s] = temp[s];
    }
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        std::vector<int> temp(nums.size());
        MergeSort(nums, temp, 0, nums.size()-1);
        return nums;
    }
};