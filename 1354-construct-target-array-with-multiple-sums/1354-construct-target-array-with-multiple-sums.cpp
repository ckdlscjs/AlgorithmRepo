auto fastio =[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();
class Solution 
{
public:
    bool isPossible(vector<int>& target) 
    {
        std::priority_queue<int, std::vector<int>, std::less<>> pq;
        long long sum = 0;
        for(const auto& iter : target)
        {
            pq.push(iter);
            sum += iter;
        }
        
        while(!pq.empty() && pq.top() != 1)
        {
            auto top = pq.top(); pq.pop();
            long long R = sum - top;
            if(R == 1) return true;
            if(R < 1 || top <= R || top % R == 0) return false;
            int prev = top % R;
            sum = prev + R;
            pq.push(prev);
        }
        return true;
    }
};