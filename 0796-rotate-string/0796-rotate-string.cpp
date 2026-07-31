auto fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();
class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        for(int i = 0; i < s.size(); i++)
        {
            auto temp = s.substr(1, s.size()-1) + s.substr(0, 1);
            if(goal == temp) return true;
            s = temp;
        }
        return false;
    }
};