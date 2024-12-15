#include <iostream>
#include <deque>
#include <string>
using namespace std;

struct point {
   int x, y, d;
};

int main() {
   point pt;
   int N, M;
   string map1D;
   int map[100][100];
   int dist[100][100];
   for (int i = 0; i < 100; i++) {
      for (int j = 0; j < 100; j++) {
         dist[i][j] = 999999;
      }
   }
   int dx[4] = { 1, -1, 0, 0 };
   int dy[4] = { 0,0,1,-1 };
   int top_x, top_y, top_d;
   int newx, newy, newd;
   // 맵 추가
   cin >> M >> N;
   for (int i = 0; i < N; i++) {
      cin >> map1D;
      for (int j = 0; j < M; j++) {
         map[i][j] = map1D[j] - 48;
      }
   }

   deque <point> Q_room;
   pt.x = 0;
   pt.y = 0;
   pt.d = 0;
   Q_room.push_back(pt);
   dist[0][0] = 0;
   while (!Q_room.empty()) {
      top_x = Q_room.front().x;
      top_y = Q_room.front().y;
      top_d = Q_room.front().d;
      Q_room.pop_front();
      if (top_x == (M - 1) && top_y == (N - 1)) { // 정답 찾음
            cout << top_d << endl;
            return 0;
         }
      for (int dir = 0; dir < 4; dir++) {
         newx = top_x + dx[dir];
         newy = top_y + dy[dir];
         //cout << "시작좌표>> " << top_x << ", " << top_y << " 거리: " << top_d << "방향: " << dir << endl;
         //cout << "디버그 코드>> " << newx << ", " << newy << endl;
         if (newx < 0 || newx >= M || newy < 0 || newy >= N) continue; // 맵 바깥으로 나감
         
         if (dist[newy][newx] <= dist[top_y][top_x] + 1) continue; // 이미 확인한 지점

         newd = top_d + map[newy][newx];
         dist[newy][newx] = newd;
         pt.x = newx;
         pt.y = newy;
         pt.d = newd;
         if (map[newy][newx] == 0) {
            Q_room.push_front(pt);
         }
         else {
            Q_room.push_back(pt);
         }
      }
   }
}