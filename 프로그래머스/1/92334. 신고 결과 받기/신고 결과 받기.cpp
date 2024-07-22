#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) 
{  
    std::unordered_map<std::string, int> report_results;
    for(const auto& iter : id_list)
        report_results[iter] = 0;
        
    std::unordered_map<std::string, std::unordered_set<std::string>> reports_count;
    for(auto iter : report)
    {
        std::string id = iter.substr(0, iter.find(' '));
        iter.erase(0, iter.find(' ') + 1);
        std::string rep = iter;
        reports_count[rep].insert(id);
    }
    for(const auto& iter : reports_count)
    {
        if(iter.second.size() >= k)
            for(const auto& user : iter.second)
                report_results[user]++;
    }
    
    std::vector<int> answer;
    for(const auto& iter : id_list)
        answer.push_back(report_results[iter]);
    return answer;
}