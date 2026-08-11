class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int lo = 0, hi = arr.size()-1;
        while(lo + 1 < hi)
        {
            int mid = (lo + hi) / 2;
            if(arr[mid] < arr[mid+1]) lo = mid;
            else hi = mid;
        }
        return hi;
    }
};