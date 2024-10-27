#include <bits/stdc++.h>
using namespace std;

const int cacheHit = 1, cacheMiss = 5;

int solution(int cacheSize, vector<string> cities) 
{
    if (cacheSize == 0) return cities.size() * cacheMiss; // 캐시 크기가 0인 경우 모두 cacheMiss입니다.
    
    int answer = 0;
    list<string> cache; // LRU 순서를 유지하는 리스트
    unordered_map<string, list<string>::iterator> cacheMap; // 도시 이름을 리스트의 iterator와 매핑
    
    for (auto& city : cities) 
    {
        // 대소문자 무시를 위해 소문자를 대문자로 변환
        transform(city.begin(), city.end(), city.begin(), ::toupper);
        
        if (cacheMap.find(city) != cacheMap.end()) // cache hit
        {
            // 해당 도시를 캐시의 맨 뒤로 이동
            cache.erase(cacheMap[city]); 
            cache.push_back(city);
            cacheMap[city] = --cache.end();
            answer += cacheHit;
        } 
        else // cache miss
        {
            if (cache.size() == cacheSize) // 캐시가 가득 찬 경우
            {
                // LRU 도시를 제거
                cacheMap.erase(cache.front());
                cache.pop_front();
            }
            // 새로운 도시를 캐시에 추가
            cache.push_back(city);
            cacheMap[city] = --cache.end();
            answer += cacheMiss;
        }
    }
    return answer;
}
