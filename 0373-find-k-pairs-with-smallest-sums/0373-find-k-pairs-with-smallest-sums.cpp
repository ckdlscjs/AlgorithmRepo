auto fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}(); // 👈 () 즉시 실행 추가
// tuple 대신 커스텀 구조체 정의 (속도 향상 및 가독성 업)
struct Pair {
    int sum;
    int idx1;
    int idx2;
    
    // 최소 힙(greater)으로 동작하도록 > 연산자 정의
    bool operator>(const Pair& other) const {
        return sum > other.sum;
    }
};
class Solution 
{
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
        
        // 👈 중요: k개 혹은 nums1 크기 중 더 작은 값만큼만 초기 삽입
        int n1 = nums1.size();
        int limit = std::min(n1, k);
        for(int i = 0; i < limit; i++)
        {
            pq.push({nums1[i] + nums2[0], i, 0});
        }
        std::vector<std::vector<int>> ret;
        ret.reserve(k); // 👈 결과 벡터 공간 미리 확보
        
        // 큐가 비거나 k번 반복할 때까지 수행 (예외 처리 추가)
        while(k-- && !pq.empty())
        {
            auto [sum, idx1, idx2] = pq.top(); pq.pop();
            ret.push_back({nums1[idx1], nums2[idx2]});
            
            if(idx2 + 1 < nums2.size())
            {
                pq.push({nums1[idx1] + nums2[idx2+1], idx1, idx2+1});
            }
        }
        return ret;
    }
};