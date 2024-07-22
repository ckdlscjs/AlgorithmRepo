#include <bits/stdc++.h>

using namespace std;
vector<int> solution(string msg) 
{
    std::unordered_map<std::string, int> hash_map;
    int idx = 1;
    int longest = 1;
    for(int i = 0; i < 26; i++)
    {
        std::string str = "A";
        str[0] += i;
        hash_map[str] = idx++;
    }
    vector<int> answer;
    
    while(msg.size())
    {
        int length = longest;
        std::string w = msg.substr(0,length);
        while(hash_map.find(w) == hash_map.end() && length > 1)
        {
            length--;
            w = msg.substr(0,length);
        }
        answer.push_back(hash_map[w]);
        msg.erase(0, length);
        w += msg[0];
        if(hash_map.find(w) == hash_map.end())
            hash_map[w] = idx++;
        longest = std::max(longest, (int)w.size());  
    }
    
    return answer;
}