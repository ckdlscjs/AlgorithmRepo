#include <bits/stdc++.h>
using namespace std;
const int cacheHit = 1, cacheMiss = 5;
std::unordered_map<string, std::list<string>::iterator> chks; 
std::list<string> cache;
int solution(int cacheSize, vector<string> cities) 
{
    if (cacheSize == 0) return cities.size() * cacheMiss;
    int answer = 0;
    for (auto& iter : cities) 
    {
        std::transform(iter.begin(), iter.end(), iter.begin(), ::tolower);
        if(chks.find(iter) == chks.end())
        {
            answer += cacheMiss;
        }
        else
        {
            answer += cacheHit;
            cache.erase(chks[iter]);
        }
        cache.push_back(iter);
        chks[iter] = --cache.end();
        if(cache.size() > cacheSize)
        {
            chks.erase(cache.front());
            cache.pop_front();
        }
    }
    return answer;
}
