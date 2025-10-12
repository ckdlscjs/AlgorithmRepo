#include <bits/stdc++.h>

using namespace std;
std::list<std::string> cache;
std::unordered_map<std::string, std::list<std::string>::iterator> chks; 
int solution(int cacheSize, vector<string> cities) 
{
    if(cacheSize <= 0) return cities.size() * 5;
    int answer = 0;
    for(auto& iter : cities)
    {
        std::transform(iter.begin(), iter.end(), iter.begin(), ::tolower);
        if(chks.size() && chks.find(iter) != chks.end())
        {
            answer += 1;
            cache.erase(chks[iter]);
        }
        else
        {
            answer += 5;
        }
        cache.push_front(iter);
        chks[iter] = cache.begin();
        if(cache.size() > cacheSize)
        {
            chks.erase(cache.back());
            cache.pop_back();
        }
    }
    return answer;
}