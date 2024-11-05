#include <bits/stdc++.h>
struct Node
{
  int val;
  Node* left;
  Node* right;
  Node(int _val)
  {
    val = _val;
    left = right = nullptr;
  }
  virtual ~Node()
  {
    left = right = nullptr;
  }
};
struct Deque
{
  int size;
  Node* head;
  Node* tail;
  Deque()
  {
    size = 0;
    head = tail = nullptr;
  }
  virtual ~Deque()
  {
    while(head)
    {
      Node* next = head->right;
      delete head;
      head = next;
    }
  }
  void PushFront(int _val)
  {
    size++;
    Node* newNode = new Node(_val);
    if(head == nullptr && tail == nullptr)
    {
      tail = newNode;
      head = newNode;
      return;
    }
    head->left = newNode;
    newNode->right = head;
    head = newNode;
  }
  void PushBack(int _val)
  {
    size++;
    Node* newNode = new Node(_val);
    if(head == nullptr && tail == nullptr)
    {
      tail = newNode;
      head = newNode;
      return;
    }
    tail->right = newNode;
    newNode->left = tail;
    tail = newNode;
  }
  void PopFront()
  {
    if(size <= 0 || head == nullptr)
    {
      return;
    }
    size--;
    Node* del = head;
    head = head->right;
    if(head != nullptr)
      head->left = nullptr;
    else
      tail = nullptr;
    delete del;
  }
  void PopBack()
  {
    if(size <= 0 || tail == nullptr)
    {
      return;
    }
    size--;
    Node* del = tail;
    tail = tail->left;
    if(tail != nullptr)
      tail->right = nullptr;
    else
      head = nullptr;
    delete del;
  }
  int Size()
  {
    return size;
  }
  int Empty()
  {
    return size ? 0 : 1;
  }
  int Front()
  {
    return head == nullptr ? -1 : head->val;
  }
  int Back()
  {
    return tail == nullptr ? -1 : tail->val;
  }
};

int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  Deque dq;
  int N, M, ans = 0;
  std::cin >> N >> M;
  for(int i = 1; i <= N; i++)
    dq.PushBack(i);
  for(int i = 0; i < M; i++)
  {
    int val = 0;
    std::cin >> val;
    if(dq.Front() == val)
    {
      dq.PopFront();
      continue;
    }
    else
    {
      int idx = 0;
      Node* temp = dq.head;
      for(idx = 0; idx < dq.Size();)
      {
        if(temp->val == val)
        {
          break;
        }
        temp = temp->right;
        idx++;
      }
      //std::cout << dq.Size() << ", " << idx << '\n';
      if(idx <= dq.Size() / 2)
      {
        while(dq.Front() != val)
        {
          dq.PushBack(dq.Front());
          dq.PopFront();
          ans++;
        }
      }
      else
      {
        while(dq.Front() != val)
        {
          dq.PushFront(dq.Back());
          dq.PopBack();
          ans++;
        }
      }
      dq.PopFront();
    }
  }
  std::cout << ans;
  return 0;
}