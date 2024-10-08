//https://school.programmers.co.kr/learn/courses/30/lessons/81303
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int idx;
    Node* prev = nullptr;
    Node* next = nullptr;
    Node(int _idx) : idx(_idx), prev(nullptr), next(nullptr) {}

};
Node* linkedList = nullptr;
Node* cursor = nullptr;
string solution(int n, int k, vector<string> cmd) 
{
    string answer = "";
    for(int i = 0; i < n; i++)
    {
        answer += "X";
        Node* newNode = new Node(i);
        if(!linkedList)
        {
            linkedList = newNode;
        }
        else
        {
            linkedList->next = newNode;
            newNode->prev = linkedList;
            linkedList = newNode;
        }
        if(i == k)
            cursor = linkedList;
    }
    std::stack<Node*> st;
    
    for(const auto& iter : cmd)
    {
        if(iter[0] == 'U')
        {
            for(int i = 0; i < std::stoi(iter.substr(2)); i++)
                cursor = cursor->prev;
        }
        else if(iter[0] == 'D')
        {
            for(int i = 0; i < std::stoi(iter.substr(2)); i++)
                cursor = cursor->next;
        }
        else if(iter[0] == 'C')
        {
            st.push(cursor);
            Node* temp = cursor;
            if(temp->next == nullptr)
            {
                cursor = temp->prev;
                cursor->next = nullptr;
            }
            else
            {
                cursor = temp->next;
                if(cursor->prev)
                    cursor->prev = temp->prev;
                if(cursor->prev)
                    cursor->prev->next = cursor;
            }
        }
        else
        {
            Node* insert = st.top();
            st.pop();
            if(insert->prev)
                insert->prev->next = insert;
            if(insert->next)
                insert->next->prev = insert;
        }
    }
    
    while(cursor->prev)
        cursor = cursor->prev;
    while(cursor)
    {
        answer[cursor->idx] = 'O';
        cursor = cursor->next;
    }
    
    
    return answer;
}