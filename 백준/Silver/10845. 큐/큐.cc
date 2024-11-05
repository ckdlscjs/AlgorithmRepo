#include <bits/stdc++.h>
int N;
struct Queue
{
  int size, front, tail;
  int arr[10'005];
  Queue(int _size)
  {
    size = _size;
    front = tail = 0;
    std::memset(arr, 0, sizeof(arr));
  }
  void Push(int _val)
  {
    if(tail >= size) return;
    arr[tail++] = _val;
  }
  void Pop()
  {
    if(front == tail)
    {
      std::cout << -1 << '\n';
      return;
    }
    std::cout << arr[front++] <<'\n';
  }
  void Size()
  {
    std::cout << tail - front << '\n';
  }
  void Empty()
  {
    std::cout << (tail==front ? 1 : 0) << '\n';
  }
  void Front()
  {
    if(front == tail)
    {
      std::cout << -1 << '\n';
      return;
    }
    std::cout << arr[front] << '\n';
  }
  void Back()
  {
    if(front == tail)
    {
      std::cout << -1 << '\n';
      return;
    }
    std::cout << arr[tail - 1] << '\n';
  }
};
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  Queue q(N);
  int val;
  std::string order;
  for(int i = 0; i < N; i++)
  {
    std::cin >> order;
    if(order == "push")
    {
      std::cin >> val;
      q.Push(val);
    }
    else if(order == "pop")
    {
      q.Pop();
    }
    else if(order == "size")
    {
      q.Size();
    }
    else if(order == "empty")
    {
      q.Empty();
    }
    else if(order == "front")
    {
      q.Front();
    }
    else if(order == "back")
    {
      q.Back();
    }
  }
  return 0;
}