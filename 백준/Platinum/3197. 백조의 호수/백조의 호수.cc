/*
1.접근방식:
bfs, 시뮬레이션문제 순서를 물이녹고->백조가이동하고 순으로 구현하였다, 시간을 최적화하기위해
다음이동하는 횟수의 큐에대한 복사등을 최적화 하였다, 시뮬레이션을 수행하되 물이 현재 가능한 크기만 녹고 인접은 다음에 수행한다
백조는 현재 가능위치를 이동하되 0_1bfs의 효과를 내기위해 next_queue혹은 deque을 이용하여 최적화하였다
dist로 cnt를 제외하고 먼저 구현해봤으나 메모리사용량만 높아져(1*1502*1502 vs 4*1502*1502) visited로 변경하고 res를 계수하는식으로 최종수정하였다

2.시간복잡도:
O(R*C*4)
*/
#include <bits/stdc++.h>
#define pii std::pair<int, int>
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int R, C, res;
bool vistied[1502][1502];
char arr[1502][1502];
std::deque<pii> dq_s;
std::queue<pii> q_i;
std::vector<pii> swans;
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> R >> C;
    for(int r = 0; r < R; r++)
    {
        std::cin >> arr[r];
        for(int c = 0; c < C; c++)
        {
            if(arr[r][c] == '.' || arr[r][c] == 'L') q_i.push({r, c});
            if(arr[r][c] == 'L') swans.push_back({r, c});
        }
    }
    vistied[swans[0].first][swans[0].second] = true;
    dq_s.push_front(swans[0]);
    while(vistied[swans[1].first][swans[1].second] == false)
    {
        int size_qi = q_i.size();
        for(int i = 0; i < size_qi; i++)
        {
            auto cur = q_i.front(); 
            q_i.pop();
            for(int dir = 0; dir < 4; dir++)
            {
                int ny = cur.first + dy[dir];
                int nx = cur.second + dx[dir];
                if(ny < 0 || nx < 0 || ny >= R || nx >= C || arr[ny][nx] != 'X') continue;
                q_i.push({ny, nx});
                arr[ny][nx] = '.';
            }
        }
        while(dq_s.size() && arr[dq_s.front().first][dq_s.front().second] != 'X')
        {
            auto cur = dq_s.front();
            dq_s.pop_front();
            for(int dir = 0; dir < 4; dir++)
            {
                int ny = cur.first + dy[dir];
                int nx = cur.second + dx[dir];
                if(ny < 0 || nx < 0 || ny >= R || nx >= C || vistied[ny][nx]) continue;
                vistied[ny][nx] = true;
                if(arr[ny][nx] == '.' || arr[ny][nx] == 'L') dq_s.push_front({ny, nx});
                else dq_s.push_back({ny, nx});
            }
        }
        res++;
    }
    std::cout << res;
    return 0;
}
