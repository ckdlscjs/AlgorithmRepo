#include <bits/stdc++.h>
int arr[105][105], cy, cx, y, x, dir = 1;
int solution(int n, int w, int num) 
{
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