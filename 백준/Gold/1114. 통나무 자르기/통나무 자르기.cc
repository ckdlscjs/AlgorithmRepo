#include <bits/stdc++.h>
int L, K, C, arr[10'005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> L >> K >> C;
  for(int i = 0; i < K; i++) std::cin >> arr[i];
  std::sort(arr, arr+K); //정렬
  K = std::unique(arr, arr+K) - arr; //정렬후 중복값제거
  arr[K] = L; //arr[i+1] - arr[i], 조각사이의 범위를 세기위해 끝에 l추가
  int lo = 0, hi = L, ans = L; //1 ~ l-1까지 조각화
  while(lo + 1 < hi)
  {
    int mid = (lo + hi) / 2;
    int curL = L, c = C;
    for(int i = K-1; i >= 0 && c > 0; i--)
    {
      if(curL - arr[i] > mid) //현재 자를 조각(mid)보다 크다면 자름
      {
        if(arr[i+1] - arr[i] > mid) //자를위치 사이가 현재크기보다 크다면불가
        {
          curL = L;
          c = 0;
          break;
        }
        curL = arr[i+1]; //자를수 있으므로 이전값을 기준으로 잘라냄
        c--;
      }
    }
    if(c > 0) curL = arr[0]; //다 잘라내고 횟수가 남았다면 처음위치는 가장 작은위치로
    if(curL <= mid) //최대 조각 길이가 타겟조각(mid)보다 작거나 같다면 성공
    {
      hi = mid; //최대길이 t/f경계선에서 t
      ans = curL; //자르는 첫 최소 위치
    }
    else lo = mid;
  }
  std::cout << hi << ' ' << ans;
  return 0;
}