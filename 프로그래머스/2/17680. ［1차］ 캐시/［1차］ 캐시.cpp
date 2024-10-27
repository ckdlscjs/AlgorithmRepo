//https://school.programmers.co.kr/learn/courses/30/lessons/17680
#include <bits/stdc++.h>
using namespace std;
std::unordered_set<std::string> chks;
std::deque<std::string> cache;
int solution(int cacheSize, vector<string> cities) 
{
    int answer = 0;
    for(auto& iter : cities)
    {
        for(auto& ch : iter)
        {
            if(ch >= 'a')
                ch -= 32;
        }
        if(chks.find(iter) == chks.end())
        {
            chks.insert(iter);
            cache.push_back(iter);
            if(cache.size() > cacheSize)
            {
                chks.erase(cache.front());
                cache.pop_front();
            }
            answer += 5;
            continue;
        }
        else
        {
            std::stack<std::string> st;
            while(cache.front() != iter)
                st.push(cache.front()), cache.pop_front();
            cache.push_back(cache.front());
            cache.pop_front();
            while(st.size())
                cache.push_front(st.top()), st.pop();
            answer+=1;
        }
    }
    
    return answer;
}