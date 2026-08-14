class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        long long lo = 0, hi = std::sqrt(c);
        while(lo <= hi)
        {
            long long sum = lo*lo + hi*hi;
            if(sum == c) return true;
            if(sum < c) lo++;
            else hi--;
        }
        return false;
    }
};