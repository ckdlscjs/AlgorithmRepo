#include <string>
#include <vector>

using namespace std;

int solution(string s) 
{
    int answer = 0;
    std::string st;
    int prev = 0;
    for(const auto& ch : s)
    {
        if(ch == ' ' && st.size())
        {
            prev = std::stoi(st);
            answer += prev;
            st = "";
            continue;
        }
        else if(ch == 'Z')
        {
            answer -= prev;
            continue;
        }
        st += ch;
    }
    if(st.size())
        answer += std::stoi(st);
    return answer;
}