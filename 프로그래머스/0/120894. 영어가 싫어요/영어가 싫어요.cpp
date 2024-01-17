#include <bits/stdc++.h>
using namespace std;
std::map<std::string, int> inputs;
long long solution(string numbers) 
{
    long long answer = 0;
    inputs["zero"] = 0;
    inputs["one"] = 1;
    inputs["two"] = 2;
    inputs["three"] = 3;
    inputs["four"] = 4;
    inputs["five"] = 5;
    inputs["six"] = 6;
    inputs["seven"] = 7;
    inputs["eight"] = 8;
    inputs["nine"] = 9;
    int idx = 0;
    while(idx < numbers.size())
    {
        answer *= 10;
        std::string str;
        for(int i = 3; i <= 5; i++)
        {
            str = numbers.substr(idx, i);
            if(inputs.find(str) == inputs.end())
                continue;
            answer += inputs[str];
            idx += i;
            break;
        }
        std::cout << answer <<'\n';
    }
    return answer;
}