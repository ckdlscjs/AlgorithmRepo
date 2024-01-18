#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) 
{
    int answer = 0;
    for(const auto& num : array)
    {
        std::string str = std::to_string(num);
        while(str.size() && str.find('7') != std::string::npos)
        {
            str.erase(str.find('7'),1);
            answer++;
        }
    }
    return answer;
}