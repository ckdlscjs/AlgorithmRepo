#include <bits/stdc++.h>
using namespace std;
int psums[1'000'005];
vector<int> solution(vector<int> sequence, int k) 
{
    for(int i = 1; i <= sequence.size(); i++)
    {
        psums[i] = sequence[i-1];
        psums[i] += psums[i-1];
    }
    vector<int> answer(2, sequence.size()-1);
    int l = 1, r = 1, len = sequence.size();
    
    while(l <= r && r <= sequence.size())
    {
        int sum = psums[r] - psums[l-1];
        if(sum == k)
        {
            if(r-l+1 < len)
            {
                answer[0] = l-1;
                answer[1] = r-1;
                len = r-l+1;
            }
            else if(r-l+1 == len && l-1 < answer[0])
            {
                answer[0] = l-1;
                answer[1] = r-1;
            }
            r++;
        }
        else if(sum < k) r++;
        else if(sum > k) l++;
    }
    return answer;
}