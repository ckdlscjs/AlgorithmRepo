#include <bits/stdc++.h>
using namespace std;
bool chk[50'005];
int solution(vector<int> arr, int limit) 
{
    int answer = 0;
    std::sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++)
    {
        if(chk[i]) continue;
        chk[i] = true;
        int lo = i, hi = arr.size();
        while(lo + 1 < hi)
        {
            int mid = (lo + hi) / 2;
            if(arr[i] + arr[mid] > limit) hi = mid;
            else if(arr[i] + arr[mid] <= limit && chk[mid]) hi = mid;
            else lo = mid;
        }
        if(arr[i] + arr[lo] <= limit && !chk[lo])
        {
            chk[lo] = true;
        }
        
        answer++;
    }
    return answer;
}