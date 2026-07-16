auto fastio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
};

class Solution 
{
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) 
    {
        std::vector<int> rets(n, 0);
        std::stack<std::pair<int, int>> st;
        for(auto iter : logs)
        {
            auto chk = iter.find(":");
            int id, st_en, stamp;
            id = std::stoi(iter.substr(0, chk));
            iter = iter.substr(chk+1);
            chk = iter.find(":");
            st_en = iter.substr(0, chk) == "start" ? 0 : 1;
            stamp = std::stoi(iter.substr(chk+1));
            //std::cout << id << ' ' << st_en << ' ' << stamp << '\n';
            if(st_en == 0)
            {
                st.push({id, stamp});
            }
            else
            {
                int amount = stamp - st.top().second + 1; st.pop();
                rets[id] += amount;
                if(st.size())
                    rets[st.top().first] -= amount;
            }
        }
        return rets;
    }
};