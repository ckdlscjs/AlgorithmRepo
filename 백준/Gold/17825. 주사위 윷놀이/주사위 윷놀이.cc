#include <bits/stdc++.h>
using namespace std;

struct Map {
    int point;
    int next[2] = {0, -1};
};

Map maps[33];  // 맵 배열
int arr[10] = {0};
int res = 0;

void Check(int idx, int sum, long long int mask, vector<int>& players) 
{
  if (idx >= 10) 
  {  
    res = max(res, sum);
    return;
  }
  for (int i = 0; i < players.size(); i++) 
  {
    if (players[i] >= 32)
      continue;
    int cur = players[i];
    for (int j = 0; j < arr[idx]; j++) 
    {
      players[i] = (j == 0 && maps[players[i]].next[1] != -1) ? maps[players[i]].next[1] : maps[players[i]].next[0];
      if (players[i] >= 32)
        break;
    }
    
    if (players[i] >= 32 || !(mask & (1LL << players[i]))) 
    {
      mask ^= (1LL << cur);
      Check(idx + 1, sum + maps[players[i]].point, mask | (1LL << players[i]), players); 
      mask ^= (1LL << cur); 
    }
    players[i] = cur;
  }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i <= 19; i++) 
    {
        maps[i].point = i * 2;
        maps[i].next[0] = i + 1;
    }
    maps[20].point = 40;
    maps[20].next[0] = 32;
    
    maps[5].next[1] = 21;  
    maps[10].next[1] = 24;
    maps[15].next[1] = 26;

    maps[21].point = 13;
    maps[21].next[0] = 22;
  
    maps[22].point = 16;
    maps[22].next[0] = 23;
    
    maps[23].point = 19;
    maps[23].next[0] = 29;
    
    maps[24].point = 22;
    maps[24].next[0] = 25;
    
    maps[25].point = 24;
    maps[25].next[0] = 29;
    
    maps[26].point = 28;
    maps[26].next[0] = 27;
    
    maps[27].point = 27;
    maps[27].next[0] = 28;
    
    maps[28].point = 26;
    maps[28].next[0] = 29;

    maps[29].point = 25;
    maps[29].next[0] = 30;

    maps[30].point = 30;
    maps[30].next[0] = 31;

    maps[31].point = 35;
    maps[31].next[0] = 20;

    maps[32].point = 0; 
    maps[32].next[0] = 32;
    
    for (int i = 0; i < 10; i++)
        cin >> arr[i];
    vector<int> players(4, 0);
    Check(0, 0, 0, players);
    cout << res;
    return 0;
}