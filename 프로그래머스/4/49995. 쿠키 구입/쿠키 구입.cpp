
#include <bits/stdc++.h>
using namespace std;
const int MaxN = 2005;
int sums[MaxN];
//(1 <= l <= m <= r <= N)
int solution(vector<int> cookie) {
    int answer = 0;
    int sum = 0;
    for(int i = 1; i <= cookie.size(); i++)
    {
        sums[i] = sums[i-1] + cookie[i-1];
    }

    for(int m = 1; m < cookie.size(); m++)
    {
        for(int r = m + 1; r <= cookie.size(); r++)
        {
            int sum_left = sums[m];
            int sum_right = sums[r] - sums[m];
            if(sum_right <= answer|| sum_right > sum_left)
                continue;
            for(int l = 0; l < m; l++)
            {
                if(sum_left - sums[l] == sum_right)
                {
                    answer = sum_right;
                    break;
                } 
            }
        }
    }
    return answer;
}