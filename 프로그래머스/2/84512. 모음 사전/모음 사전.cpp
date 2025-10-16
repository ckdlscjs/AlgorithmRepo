#include <bits/stdc++.h>

using namespace std;
std::unordered_map<int, char> ch;
std::unordered_map<std::string, int> words;
int idx = 0;
void Check(std::string str)
{
    //std::cout << str << '\n';
    words[str] = idx++;
    if(str.size() >= 5) return;
    for(int i = 0; i < 5; i++)
    {
        str += ch[i];
        Check(str);
        str.pop_back();
    }
}
int solution(string word) 
{
    ch[0] = 'A';
    ch[1] = 'E';
    ch[2] = 'I';
    ch[3] = 'O';
    ch[4] = 'U';
    Check("");
    return words[word];
}