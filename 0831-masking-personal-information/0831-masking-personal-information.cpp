class Solution {
public:
    string maskPII(string s) 
    {
        std::string ret;
        auto at = s.find('@');
        if(at != std::string::npos)
        {
            //std::cout << "mail";
            if('A' <= s[0] && s[0] <= 'Z')
                s[0] += 32;
            if('A' <= s[at-1] && s[at-1] <= 'Z')
                s[at-1] += 32;
            ret += s[0];
            ret += "*****";
            ret += s[at-1];
            ret += '@';
            for(int i = (int)(at+1); i < s.size(); i++)
            {
                if(s[i] == '.')
                {
                    ret += '.';
                    continue;
                }
                ret += s[i] <= 'Z' ? s[i] + 32 : s[i];
            }    
        }
        else
        {
            //std::cout << "phone";
            int cnt = 0;
            std::string local;
            for(const auto& iter : s)
            {
                if(!std::isdigit(iter)) continue;
                local += iter;
                cnt++;
            }
            if(cnt == 10)
                ret = "***-***-";
            else if(cnt == 11)
                ret = "+*-***-***-";
            else if(cnt == 12)
                ret = "+**-***-***-";
            else if(cnt == 13)
                ret = "+***-***-***-";
            ret += local[cnt-4];
            ret += local[cnt-3];
            ret += local[cnt-2];
            ret += local[cnt-1];
        }
        return ret;
    }
};