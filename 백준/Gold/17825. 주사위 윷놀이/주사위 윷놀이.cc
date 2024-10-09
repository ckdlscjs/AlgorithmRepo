#include <bits/stdc++.h>
using namespace std;

struct Map {
    int point;
    int next[2];  // 일반 경로와 파란색 경로
};

Map maps[33];  // 맵 배열
int arr[10] = {0};
int res = 0;

void Check(int idx, int sum, long long int mask, vector<int>& players) {
    if (idx >= 10) {  // 주사위를 모두 사용한 경우
        res = max(res, sum);
        return;
    }

    for (int i = 0; i < players.size(); i++) {
        if (players[i] >= 32)  // 도착한 경우
            continue;
        int cur = players[i];
        // 말 이동
        for (int j = 0; j < arr[idx]; j++) {
            if (j == 0 && maps[players[i]].next[1] != -1)  // 파란색 경로 있는 경우
                players[i] = maps[players[i]].next[1];
            else
                players[i] = maps[players[i]].next[0];

            if (players[i] >= 32)  // 도착한 경우
                break;
        }

        if (players[i] >= 32 || !(mask & (1LL << players[i]))) {
            mask ^= (1LL << cur);  // 현재 말의 위치 제거
            Check(idx + 1, sum + maps[players[i]].point, mask | (1LL << players[i]), players);  // 새 위치에서 체크
            mask ^= (1LL << cur);  // 상태 복구
        }

        players[i] = cur;  // 말 위치 복구
    }
}

void makeMap() {
    // 기본 경로 세팅 (다음 위치만 넣으면 됨)
    for (int i = 0; i <= 19; i++) {
        maps[i].point = i * 2;
        maps[i].next[0] = i + 1;
        maps[i].next[1] = -1;
    }
    maps[20].point = 40;
    maps[20].next[0] = 32;
    maps[20].next[1] = -1;
    
    maps[5].next[1] = 21;  // 파란색 경로
    maps[10].next[1] = 24;
    maps[15].next[1] = 26;

    maps[21].point = 13;
    maps[21].next[0] = 22;
    maps[21].next[1] = -1;
  
    maps[22].point = 16;
    maps[22].next[0] = 23;
    maps[22].next[1] = -1;
    
    maps[23].point = 19;
    maps[23].next[0] = 29;
    maps[23].next[1] = -1;
    
    maps[24].point = 22;
    maps[24].next[0] = 25;
    maps[24].next[1] = -1;
    
    maps[25].point = 24;
    maps[25].next[0] = 29;
    maps[25].next[1] = -1;
    
    maps[26].point = 28;
    maps[26].next[0] = 27;
    maps[26].next[1] = -1;
    
    maps[27].point = 27;
    maps[27].next[0] = 28;
    maps[27].next[1] = -1;
    
    maps[28].point = 26;
    maps[28].next[0] = 29;
    maps[28].next[1] = -1;

    maps[29].point = 25;
    maps[29].next[0] = 30;
    maps[29].next[1] = -1;

    maps[30].point = 30;
    maps[30].next[0] = 31;
    maps[30].next[1] = -1;

    maps[31].point = 35;
    maps[31].next[0] = 20;
    maps[31].next[1] = -1;

    maps[32].point = 0;  // 도착지점
    maps[32].next[0] = 32;  // 도착한 상태를 유지
    maps[32].next[1] = -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 입력 받기
    for (int i = 0; i < 10; i++)
        cin >> arr[i];

    // 맵 설정
    makeMap();

    vector<int> players(4, 0);  // 4개의 말 초기화
    Check(0, 0, 0, players);  // 말 이동 체크

    // 결과 출력
    cout << res;
    return 0;
}
