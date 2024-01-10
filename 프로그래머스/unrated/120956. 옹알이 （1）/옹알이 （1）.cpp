#include <bits/stdc++.h>
using namespace std;
std::vector<std::string> checkword;
int solution(vector<string> babbling) 
{
    checkword.push_back("aya");
    checkword.push_back("ye");
    checkword.push_back("woo");
    checkword.push_back("ma");
    int answer = 0;
    for(auto str : babbling)
    {
        int count = 0;
        for(const auto& strcheck : checkword)
        {
            while(str.find(strcheck) != str.npos)
            {
                int idx = str.find(strcheck);
                for(int i = 0; i < strcheck.size(); i++)
                {
                    str[idx + i] = '.';
                    count++;
                }
                    
            }
        }
        if(count == str.size())
        {
            std::cout << str <<'\n';
            answer++;
        }
    }
    
    return answer;
}