#include <bits/stdc++.h>

using namespace std;
std::map<std::string, std::string> datas;
string solution(vector<string> id_pw, vector<vector<string>> db) 
{
    for(const auto& iter : db)
    {
        datas[iter[0]] = iter[1];
    }
    if(datas.find(id_pw[0]) != datas.end())
        return datas[id_pw[0]] == id_pw[1] ? "login" : "wrong pw";
    return "fail";
}