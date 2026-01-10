#include <bits/stdc++.h>

using namespace std;
//0행~마지막행을 벗어나지 않는다
//U -> 현재칸에서 X칸위
//D -> 현재칸에서 X칸아래
//C -> 현재선택칸 삭제후 아래행을 선택한다, 마지막행일경우 윗행을선택한다
//Z -> 최근 삭제행을 되돌린다, 현재선택행이 바뀌지않는다
struct Node
{
    int value;
    Node* prev;
    Node* next;
};
std::string answer;
Node* cursor;
Node* lists;
std::stack<Node*> st;
string solution(int n, int k, vector<string> cmd) 
{
    answer = std::string(n, 'O');
    for(int i = 0; i < n; i++)
    {
        Node* newNode = new Node();
        newNode->value = i;
        if(lists)
            lists->next = newNode;
        newNode->prev = lists;
        lists = newNode;
    }
    while(lists->prev != nullptr)
        lists = lists->prev;
    cursor = lists;
    for(int i = 0; i < k; i++)
        cursor = cursor->next;

    for(const auto& iter : cmd)
    {
        int X;
        if(iter[0] == 'U')
        {
            X = std::stoi(iter.substr(2));
            for(int i = 0; i < X && cursor->prev != nullptr; i++)
                cursor = cursor->prev;
        }
        else if(iter[0] == 'D')
        {
            X = std::stoi(iter.substr(2));
            for(int i = 0; i < X && cursor->next != nullptr; i++)
                cursor = cursor->next;
        }
        else if(iter[0] == 'C')
        {
            answer[cursor->value] = 'X';
            st.push(cursor);
            Node* prevNode = cursor->prev;
            Node* nextNode = cursor->next;
            if(prevNode != nullptr)
                prevNode->next = nextNode;
            if(nextNode == nullptr)
            {
                 cursor = prevNode; 
            }
            else
            {
                cursor = nextNode;
                cursor->prev = prevNode; 
            }  
        }
        else if(iter[0] == 'Z')
        {
            auto cur = st.top();
            st.pop();
            answer[cur->value] = 'O';
            if(cur->prev == nullptr)
            {
                Node* nextNode = cur->next;
                nextNode->prev = cur;
            }
            else if(cur->next == nullptr)
            {
                Node* prevNode = cur->prev;
                prevNode->next = cur;
            }
            else
            {
                Node* nextNode = cur->next;
                Node* prevNode = cur->prev;
                prevNode->next = cur;
                nextNode->prev = cur;
            }
        }
    }
    
    return answer;
}