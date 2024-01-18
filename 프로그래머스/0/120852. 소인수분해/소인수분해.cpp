#include <string>
#include <vector>

using namespace std;
bool prime[10010];
vector<int> solution(int n) 
{
    vector<int> answer;
    for(int i = 2; i < 10010; i++)
    {
        if(prime[i])
            continue;
        for(int j = i * 2; j < 10010; j += i)
            prime[j] = true;
    }
    for(int i = 2; i <= n; i++)
    {
        if(n % i == 0 && !prime[i])
            answer.push_back(i);
    }
    
    return answer;
}