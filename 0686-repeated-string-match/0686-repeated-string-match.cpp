class Solution {
public:
    int repeatedStringMatch(string a, string b) 
    {
        if(b.empty()) return 0;
        int cnt = b.size() * 2 / a.size();
        if(cnt <= 0) cnt = 1;
        std::string str;
        for(int i = 0; i < cnt*2; i++)
            str += a;
        auto iter = str.find(b);
        if(iter == std::string::npos) return -1;
        int length = iter + b.size();
        return length % a.size() ? length / a.size() + 1 : length / a.size();
    }
}; 