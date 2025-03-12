#include <bits/stdc++.h>
int arr[110][105];
int solution(int n, int w, int num) 
{
    int cy, cx;
    int y = 0, x = 0, dir = 1;
    for(int i = 1; i <= n; i++)
    {
        arr[y][x] = i;
        if(i == num)
        {
            cy = y;
            cx = x;
        }
        if(i % w == 0)
        {
            dir *= -1;
            y++;
        }
        else
            x += dir;
    }
    int answer = 0;
    while(arr[cy][cx])
    {
        cy += 1;
        answer++;
    }
    return answer;
}