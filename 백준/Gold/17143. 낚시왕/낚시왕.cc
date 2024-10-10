#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
struct Shark
{
    int y;
    int x;
    int s;
    int d;
    int z;
    Shark() {}
    Shark(int _y, int _x, int _s, int _d, int _z) : y(_y), x(_x), s(_s), z(_z)
    {
        d = _d == 1 ? 0 : _d == 2 ? 2 : _d == 3 ? 1 : 3;
    }
};

Shark arr[105][105];  // 상어 정보 저장
std::queue<Shark> sharks;  // 이동 중인 상어를 저장할 큐
int R, C, M, r, c, s, d, z, res;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    std::cin >> R >> C >> M;
    
    // 상어 입력 처리
    for (int i = 0; i < M; i++)
    {
        std::cin >> r >> c >> s >> d >> z;
        arr[r][c] = Shark(r, c, s, d, z);  // 배열에 상어 정보를 직접 저장
    }

    // 각 열(t)마다 상어 잡는 루프
    for (int t = 1; t <= C; t++)
    {
        // 땅에서 가장 가까운 상어 잡기
        for (int i = 1; i <= R; i++)
        {
            if (arr[i][t].z > 0)  // 상어가 있으면
            {
                res += arr[i][t].z;  // 상어 크기 더함
                arr[i][t] = Shark();  // 상어 정보 초기화
                break;
            }
        }

        // 상어 이동 처리
        for (int i = 1; i <= R; i++)
        {
            for (int j = 1; j <= C; j++)
            {
                if (arr[i][j].z != 0)  // 상어가 있으면
                {
                    sharks.push(arr[i][j]);  // 큐에 상어를 추가
                    arr[i][j] = Shark();  // 상어 위치 초기화
                }
            }
        }

        // 상어 이동 시뮬레이션
        while (!sharks.empty())
        {
            Shark shark = sharks.front();
            sharks.pop();
            
            int amount;
            if (shark.d % 2 == 0)  // 상하 이동
            {
                amount = shark.s % ((R - 1) * 2);
                while (amount > 0)
                {
                    int ny = shark.y + dy[shark.d];
                    if (ny < 1 || ny > R)  // 경계에 도달하면 방향 반전
                    {
                        shark.d = (shark.d + 2) % 4;
                        continue;
                    }
                    shark.y = ny;
                    amount--;
                }
            }
            else  // 좌우 이동
            {
                amount = shark.s % ((C - 1) * 2);
                while (amount > 0)
                {
                    int nx = shark.x + dx[shark.d];
                    if (nx < 1 || nx > C)  // 경계에 도달하면 방향 반전
                    {
                        shark.d = (shark.d + 2) % 4;
                        continue;
                    }
                    shark.x = nx;
                    amount--;
                }
            }

            // 상어가 이동한 위치에 더 큰 상어가 없으면 갱신
            if (arr[shark.y][shark.x].z <= shark.z)
                arr[shark.y][shark.x] = shark;
        }
    }

    // 결과 출력
    std::cout << res;
    return 0;
}
