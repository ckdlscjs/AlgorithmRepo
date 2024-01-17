#include <string>
#include <vector>

using namespace std;

int solution(int balls, int share) 
{
    long long int answer = 1;
    for(int i = 1; i <= share; i++)
    {
        answer = (answer * balls) / i;
        balls--;
    }
    return answer;
}