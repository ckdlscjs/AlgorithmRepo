#include <bits/stdc++.h>
int N, val;
std::string order;
struct Stack
{
  int idx = 0;
  std::vector<int> st;
  Stack(int _size) : st(_size, 0) {idx = 0;}
  void Push(int val) {st[idx++] = val;}
  void Pop()
  {
    if(idx <= 0)
    {
      std::cout << -1 << '\n';
      return;
    }
    std::cout << st[idx-1] << '\n';
    idx--;
  }
  void Size()
  {
    std::cout << idx << '\n';
  }
  void Empty()
  {
    std::cout << (idx <= 0 ? 1 : 0) <<'\n';
  }
  void Top()
  {
    if(idx <= 0)
    {
      std::cout << -1 << '\n';
      return;
    }
    std::cout << st[idx-1] <<'\n';
  }
};
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  Stack st(10'005);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    std::cin >> order;
    if(order == "push")
    {
      std::cin >> val;
      st.Push(val);
    }
    else if(order == "pop")
    {
      st.Pop();
    }
    else if(order == "size")
    {
      st.Size();
    }
    else if(order == "empty")
    {
      st.Empty();
    }
    else if(order == "top")
    {
      st.Top();
    }
  }
  return 0;
}