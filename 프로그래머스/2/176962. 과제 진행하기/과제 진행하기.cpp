#include <bits/stdc++.h>
using namespace std;
int ConvInt(const std::string& str)
{
    return std::stoi(str.substr(0, 2)) * 60 + std::stoi(str.substr(3));
}
vector<string> solution(vector<vector<string>> plans) 
{
    std::sort(plans.begin(), plans.end(), [](const std::vector<std::string>& a, const std::vector<std::string>& b)->bool
              {
                  return a[1] < b[1];
              });
    
    vector<string> answer;
    std::stack<std::tuple<std::string, int>> st;
    int curtime = 0;
    for(const auto& iter : plans)
    {
        std::string itername = iter[0];
        int iterstart = ConvInt(iter[1]);
        int itertime = std::stoi(iter[2]);
        while(st.size() && curtime + std::get<1>(st.top()) <= iterstart)
        {
            answer.push_back(std::get<0>(st.top()));
            curtime += std::get<1>(st.top());
            st.pop();
        }
        if(st.size())
        {
            std::get<1>(st.top()) = curtime + std::get<1>(st.top()) - iterstart;
        }
        st.push({itername, itertime});
        curtime = iterstart;
    }
    while(st.size())
    {
        answer.push_back(std::get<0>(st.top()));
        st.pop();
    }
    return answer;
}