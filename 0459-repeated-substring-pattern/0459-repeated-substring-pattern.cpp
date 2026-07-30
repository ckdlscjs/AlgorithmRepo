class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
        auto str = (s + s).substr(1, s.size() * 2 - 2);
        return str.find(s) != std::string::npos;
    }
};