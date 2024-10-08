//https://school.programmers.co.kr/learn/courses/30/lessons/92334
#include <bits/stdc++.h>
using namespace std;
std::unordered_set<std::string> reports;
std::unordered_map<std::string, int> cnts;
std::unordered_map<std::string, std::vector<std::string>> reportlist;
vector<int> solution(vector<string> id_list, vector<string> report, int k) 
{
    for(const auto& iter : report)
    {
        if(reports.find(iter) != reports.end())
            continue;
        reports.insert(iter);
        std::string from = iter.substr(0, iter.find(" "));
        std::string to = iter.substr(iter.find(" ")+1);
        reportlist[from].push_back(to);
        cnts[to]++;
    }
    vector<int> answer;
    for(const auto& iter : id_list)
    {
        int res = 0;
        for(const auto& str : reportlist[iter])
        {
            if(cnts[str] >= k)
                res++;
        }
        answer.push_back(res);
    }
    return answer;
}