#include <bits/stdc++.h>
using namespace std;
bool arr[32];
int Check(const int N, const vector<vector<int>>& q, const vector<int>& ans, int idx, int cur)
{
    if(idx >= 5)
    {
        for(int i = 0; i < q.size(); i++)
        {
            int cnt = 0;
            for(int j = 0; j < q[i].size(); j++)
                if(arr[q[i][j]]) cnt++;
            if(cnt != ans[i]) return 0;
        }
        return 1;
    }
    int ret = 0;
    for(int i = cur; i <= N; i++)
    {
        arr[i] = true;
        ret += Check(N, q, ans, idx+1, i+1);
        arr[i] = false;
    }
    return ret;
}
int solution(int n, vector<vector<int>> q, vector<int> ans) 
{
    return Check(n, q, ans, 0, 1);
}