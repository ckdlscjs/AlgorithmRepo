#include <bits/stdc++.h>
long long int n, ret;
std::stack<std::pair<int, long long int>> st;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); 
  std::cout.tie(0);
  std::cin >> n;
  for(int i = 0; i < n; i++)
  {
    int height;
    std::cin >> height;
    long long cnt = 1;
    while(st.size() && st.top().first <= height)
    {
      ret += st.top().second; //스택에서 자신보다 사이즈가 작거나 같은 갯수의 합
      if(st.top().first == height) cnt = st.top().second + 1; //사이즈가 같다면 압축
      else cnt = 1; //사이즈가 다르다면 이전값들은 이제 볼 필요가 없음
      st.pop();
    }
    if(st.size()) ret++; //자신보다 높은 값이 스택에 남아있다
    st.push({height, cnt});
  }
  std::cout << ret;
  return 0;
}