#include <bits/stdc++.h>

using namespace std;
bool dp[2'502][2'502];
int solution(string s)
{
    int answer = 0;
    for(int i = s.size()-1; i > 0; i--)
        for(int j = 0; j < i; j++) dp[i][j] = true;
    
    for(int i = s.size()-1; i >= 0; i--)
    {
        for(int j = i; j < s.size(); j++)
        {
            if(i == j) dp[i][j] = true;
            else if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1] ? true : false;
            else dp[i][j] = false;
        }
    }
    /*
    for(int i = 0; i < s.size(); i++)
    {
        for(int j = 0; j < s.size(); j++)
        {
            std::cout << (dp[i][j] ? 1 : 0 ) << ' ';
        }
        std::cout << '\n';
    }
    */
    for(int i = s.size()-1; i >= 0; i--)
    {
        for(int j = i; j < s.size(); j++)
        {
            if(dp[i][j])
                answer = std::max(answer, j-i+1);
        }
    }
    
    return answer;
}