class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for(const auto& iter : word)
        {
            cnt += iter <= 'Z' ? 1 : 0;
        }   
        if(cnt == word.size() || cnt == 0) return true;
        if(cnt == 1 && word[0] <= 'Z') return true;
        return false;
    }
};