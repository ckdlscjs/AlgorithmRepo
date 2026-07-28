class Solution {
public:
    string licenseKeyFormatting(string s, int k) 
    {
        std::string ret;
        int cur = 0;
        for(int i = s.size()-1; i >= 0; i--)
        {
            if(s[i] == '-') continue;
            char ch = s[i];
            if('a' <= ch && ch <= 'z') ch -= 32;
            ret += ch;

            cur++;
            if(cur >= k)
            {
                cur = 0;
                ret += '-';
            }
        }
        if(ret.size() >= 2 && ret.back() == '-')
            ret.pop_back();
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};