#include <string>
#include <vector>

using namespace std;
const int MaxN = 1000005;
int NotPrime[MaxN];
int solution(int n) 
{   
    int answer = 0;
    for(int i = 2; i <= n; i++)
    {
        if(NotPrime[i])
            continue;
        answer++;
        for(int j = i + i; j <= n; j += i)
            NotPrime[j] = true;
    }
    
    return answer;
}