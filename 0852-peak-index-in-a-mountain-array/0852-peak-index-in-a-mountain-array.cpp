class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int lo = -1, hi = arr.size();
        while(lo + 1 < hi)
        {
            int mid = (lo + hi) / 2;
            if(arr[mid] < arr[mid+1]) lo = mid;
            else hi = mid;
        }
        return hi;
    }
};