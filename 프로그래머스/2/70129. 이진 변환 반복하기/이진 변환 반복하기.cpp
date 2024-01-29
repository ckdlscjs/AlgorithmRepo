#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) 
{
    //vector<int> answer;
    int count1 = 0, count2 = 0;
    while(s.size() != 1)
    {
        while(s.find('0') != std::string::npos)
        {
            //std::cout << s <<'\n';
            s.erase(s.find('0'), 1);
            count1++;
        }
        int length = s.size();
        s = "";
        while(length)
        {
            s += std::to_string(length % 2);
            length /= 2;
        }
        //std::cout << s <<'\n';
        count2++;
    }
    
    return {count2, count1};
}