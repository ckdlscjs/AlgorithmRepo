#include <string>
#include <vector>

using namespace std;

int solution(string my_string) 
{
    int answer = 0;
    for(const auto& ch : my_string)
        if('0' <= ch && ch <='9')
            answer += ch-'0';
    return answer;
}