#include <bits/stdc++.h>

using namespace std;

string solution(string polynomial) 
{
    string answer = "";
    std::vector<std::string> input_x;
    std::vector<std::string> input;
    while(polynomial.find(' ') != std::string::npos)
    {
        polynomial.erase(polynomial.find(' '), 1);
    }
    
    for(const auto& ch : polynomial)
    {
        if(ch == '+')
        {
            if(answer.find('x') != std::string::npos)
                input_x.push_back(answer);
            else
                input.push_back(answer);
            answer = "";
            continue;
        }
        answer += ch;
    }
    if(answer.find('x') != std::string::npos)
        input_x.push_back(answer);
    else
        input.push_back(answer);
    
    int count_x = 0;
    for(auto& st : input_x)
    {
        std::cout << st <<'\n';
        
        st.erase(st.find('x'));
        if(st.empty())
            count_x++;
        else
            count_x += std::stoi(st);
    }
    
    int count = 0;
    for(const auto& st : input)
    {
        std::cout << st <<'\n';
        count += std::stoi(st); 
    }
    
    answer = "";
    if(count_x)
    {
        if(count_x != 1)
            answer += std::to_string(count_x);
        answer += "x";
    }
    if(count)
    {
        if(answer.size())
            answer += " + ";
        answer += std::to_string(count);
    }
    return answer;
}