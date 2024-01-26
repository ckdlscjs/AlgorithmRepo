#include <string>
#include <vector>

using namespace std;
const int MaxN = 100005;
int area[MaxN];
int solution(int n, int m, vector<int> section) 
{
    int answer = 0;
    for(const int& idx : section)
    {
        if(area[idx])
            continue;
        for(int i = 0; i < m && idx + i <= n; i++)
                area[idx+i] = 1;
        answer++;
    }
        
    
    
    return answer;
}