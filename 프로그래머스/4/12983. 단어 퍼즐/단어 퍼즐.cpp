#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int solution(vector<string> strs, string t)
{
    int dp[20005];
    std::fill(dp, dp+20005, INF); //찾을수 없는 값 으로 초기화한다
    dp[0] = 0; //빈 문자열부터 시작
    std::unordered_set<std::string> strings; //문자열을 빠르게찾기위한 문자열 집합
    std::unordered_set<int> sizes; //카운팅을위한 길이 비중복 집합
    for(const auto& iter : strs)
    {
        strings.insert(iter);
        sizes.insert(iter.size());
    }
    for(int idx = 1; idx <= t.size(); idx++) //문자열의길이를기반으로 계산
    {
        for(const auto& size : sizes)
        {
            /*
            현재 문자열의길이 - 찾아야할 문자길이 를 감산, 해당하는 문자열이 집합에 존재할시
            현재 찾은 최소값 + 1만큼 길이를 늘린다, 찾은 문자열이 초기상태일경우
            dp[0]+1의 결과기 때문에 최소값인 1이된다
            문자열이 초기상태가 아닌경우 이전에 찾은 위치에서의 최소값 + 현재찾은 문자열갯수
            이므로 dp[이전값] + 현재찾은문자열갯수1 이 가산되어 현재값dp[idx]로 완성된다.
            */
            if(idx >= size && strings.count(t.substr(idx-size, size)))
                dp[idx] = std::min(dp[idx], dp[idx-size]+1); 
        }
    }
    
    return dp[t.size()] == INF ? -1 : dp[t.size()];
}