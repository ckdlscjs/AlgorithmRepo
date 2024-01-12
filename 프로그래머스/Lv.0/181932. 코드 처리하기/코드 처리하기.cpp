#include <string>
#include <vector>

using namespace std;

string solution(string code) 
{
    bool mode = false;
    string answer = "";
    for(int i = 0; i < code.size(); i++)
    {
        if(code[i] == '1')
            mode = !mode;
        else
        {
            if(!mode && i % 2 == 0)
                answer += code[i];
            else if(mode && i%2 != 0)
                answer += code[i];
        }
    }
    return answer.size() ? answer : "EMPTY";
}