#include <string>
#include <vector>

using namespace std;
int dp[15];
int solution(int n) 
{
    dp[0] = 1;
    dp[1] = 1;
    int answer = 0;
    for(int i = 2; i <= 11; i++)
    {
        dp[i] = i * dp[i-1];
        if(n < dp[i])
        {
            answer = i-1;
            break;
        }
    }
    
    return n ? answer : 0;
}