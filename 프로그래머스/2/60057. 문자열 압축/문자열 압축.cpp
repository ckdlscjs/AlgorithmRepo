#include <bits/stdc++.h>

using namespace std;

int solution(string s) 
{
    int answer = s.size();
    for(int i = 1; i <= s.size() / 2; i++)
    {
        std::string str = s;
        std::string result = "";
        while(str.size() >= i*2)
        {
            int cnt = 1;
            std::string origin = str.substr(0, i);
            str = str.substr(i);
            while(str.size() >= i && origin == str.substr(0, i))
            {
                cnt++;
                str = str.substr(i);
            }
            if(cnt >= 2)
                result += std::to_string(cnt);
            result += origin;
        }
        result += str;
        //std::cout << result << '\n';
        answer = std::min(answer, (int)result.size());
    }
    return answer;
}