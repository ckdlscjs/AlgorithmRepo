class Solution {
public:
    vector<int> beautifulArray(int n) 
    {
        if(n <= 1) return {1};
        std::vector<int> ls = beautifulArray((n+1)/2);
        std::vector<int> rs = beautifulArray(n/2);
        std::vector<int> ret;
        for(const auto& iter : ls)
            ret.push_back(iter*2 - 1);
        for(const auto& iter : rs)
            ret.push_back(iter*2 );
        return ret;
    }
};