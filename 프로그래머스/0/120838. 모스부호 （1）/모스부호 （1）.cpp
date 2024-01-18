#include <bits/stdc++.h>
std::map<std::string, char> morse;
using namespace std;

string solution(string letter) 
{
    morse[".-"] = 'a';
    morse["-..."] = 'b';
    morse["-.-."] = 'c';
    morse["-.."] = 'd';
    morse["."] = 'e';
    morse["..-."] = 'f';
    morse["--."] = 'g';
    morse["...."] = 'h';
    morse[".."] = 'i';
    morse[".---"] = 'j';
    morse["-.-"] = 'k';
    morse[".-.."] = 'l';
    morse["--"] = 'm';
    morse["-."] = 'n';
    morse["---"] = 'o';
    morse[".--."] = 'p';
    morse["--.-"] = 'q';
    morse[".-."] = 'r';
    morse["..."] = 's';
    morse["-"] = 't';
    morse["..-"] = 'u';
    morse["...-"] = 'v';
    morse[".--"] = 'w';
    morse["-..-"] = 'x';
    morse["-.--"] = 'y';
    morse["--.."] = 'z';
    letter += " ";
    string answer = "";
    std::string st = "";
    for(const auto& ch : letter)
    {
        if(ch == ' ')
        {
            answer += morse[st];
            st = "";
            continue;
        }
        st += ch;
    }
    
    return answer;
}