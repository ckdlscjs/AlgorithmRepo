#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) 
{
    int answer = 0;
    for(i; i <= j; i++)
    {
        std::string str = std::to_string(i);
        while(str.find(std::to_string(k)) != std::string::npos)
        {
            str.erase(str.find(std::to_string(k)), 1);
            answer++;
        }
    }
    
    return answer;
}