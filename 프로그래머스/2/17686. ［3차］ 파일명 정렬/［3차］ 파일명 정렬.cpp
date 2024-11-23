//https://school.programmers.co.kr/learn/courses/30/lessons/17686
#include <bits/stdc++.h>
using namespace std;
void split(const std::string& str, std::string& head, std::string& num)
{
    std::string temp;
    for(const auto& iter : str)
    {
        if(head.empty() && temp.size() && std::isdigit(iter))
        {
            std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            head = temp;
            temp.clear();
        }
        else if(num.empty() && head.size() && temp.size() && !std::isdigit(iter))
        {
            num = temp;
            temp.clear();
        }
        temp += iter;
    }
    if(num.empty())
    {
        num = temp;
        return;
    }
}
bool compare(const std::string& a, const std::string& b)
{
    std::string str[2][2];
    split(a, str[0][0], str[0][1]);
    split(b, str[1][0], str[1][1]);
    if(str[0][0] == str[1][0])
    {
        return std::stoi(str[0][1]) < std::stoi(str[1][1]);
    }
    return str[0][0] < str[1][0];
}
vector<string> solution(vector<string> files) 
{
    std::stable_sort(files.begin(), files.end(), compare);
    return files;
}