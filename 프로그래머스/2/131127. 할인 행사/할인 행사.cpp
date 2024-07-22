#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) 
{
    
    std::unordered_map<std::string, int> want_map;
    for(int i = 0; i < want.size(); i++)
        want_map[want[i]] = number[i];
    
    std::unordered_map<std::string, int> hash_map;
    for(int i = 0; i < 10; i++)
        hash_map[discount[i]]++;
    
    int answer = 0;
    for(int i = 0; i <= discount.size() - 10; i++)
    {
        bool valid = true;
        for(const auto& iter : want_map)
            if(hash_map[iter.first] != iter.second)
                valid = false;
        if(valid)
        {
            std::cout << i <<'\n';
            answer++;
        }
           
        hash_map[discount[i]]--;
        if(i < discount.size() - 10)
            hash_map[discount[i + 10]]++;
    }
    
    return answer;
}