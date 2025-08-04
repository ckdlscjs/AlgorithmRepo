/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, L, arr[102][102], res;
int Check()
{
    int cnt = 0;
    for(int i = 0; i < N; i++)
    {
        int cur = arr[i][0];
        int j = 1;
        int cnt_same = 1;
        for(j; j < N; j++)
        {
            if(arr[i][j] == cur) cnt_same++;
            else
            {
                if(std::abs(cur - arr[i][j]) > 1) break;
                else if(arr[i][j] > cur)
                {
                    if(cnt_same < L) break;
                    cnt_same = 1;
                }
                else
                {
                    int cnt_nxt = 0;
                    for(int l = 0; l < L && j + l < N; l++)
                    {
                        if(arr[i][j+l] == arr[i][j]) 
                            cnt_nxt++;
                    }
                    if(cnt_nxt < L) break;
                    j += L - 1;
                    cnt_same = 0;
                }
                cur = arr[i][j];
            }
        }
        if(j >= N) cnt++;
    }
    return cnt;
}
void RotateCW()
{
    int tmp[102][102];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            tmp[j][N-i-1] = arr[i][j];
    std::memcpy(arr, tmp, sizeof(tmp));
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> N >> L;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            std::cin >> arr[i][j];
    res += Check();
    RotateCW();
    res += Check();
    std::cout << res;
	return 0;
}

