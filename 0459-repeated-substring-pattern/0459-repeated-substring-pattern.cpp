class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
        for(int i = 1; i <= s.size() / 2; i++)
        {
            auto substr = s.substr(0, i);
            std::string temp;
            for(int j = 0; j < s.size() / i; j++)
                temp += substr;
            if(temp == s) return true;
        }
        return false;
    }
};