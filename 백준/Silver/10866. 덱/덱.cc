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
      std::cout << -1 << '\n';
      return;
    }
    size--;
    std::cout << head->val << '\n';
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
      std::cout << -1 << '\n';
      return;
    }
    size--;
    std::cout << tail->val << '\n';
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
  int N, val;
  std::string order;
  std::cin >> N;
  Deque dq;
  
  for(int i = 0; i < N; i++)
  {
    std::cin >> order;
    if(order == "push_front")
    {
      std::cin >> val;
      dq.PushFront(val);
    }
    else if(order == "push_back")
    {
      std::cin >> val;
      dq.PushBack(val);
    }
    else if(order == "pop_front")
    {
      dq.PopFront();
    }
    else if(order == "pop_back")
    {
      dq.PopBack();
    }
    else if(order == "size")
    {
      std::cout << dq.Size() << '\n';
    }
    else if(order == "empty")
    {
      std::cout << dq.Empty() << '\n';
    }
    else if(order == "front")
    {
      std::cout << dq.Front() <<'\n';
    }
    else if(order == "back")
    {
      std::cout << dq.Back() << '\n';
    }
  }
  
  return 0;
}