#include <bits/stdc++.h>
/*
"U X": 현재 선택된 행에서 X칸 위에 있는 행을 선택합니다.
"D X": 현재 선택된 행에서 X칸 아래에 있는 행을 선택합니다.
"C" : 현재 선택된 행을 삭제한 후, 바로 아래 행을 선택합니다. 단, 삭제된 행이 가장 마지막 행인 경우 바로 윗 행을 선택합니다.
"Z" : 가장 최근에 삭제된 행을 원래대로 복구합니다. 단, 현재 선택된 행은 바뀌지 않습니다.
n : 행 개수
k : 처음 선택된 행의 위치
cmd : 명령어들이 담긴 문자열배열
*/
using namespace std;
struct Node
{
    int idx = 0;
    Node* prev = nullptr;
    Node* next = nullptr;
    Node(int _idx) : idx(_idx), prev(nullptr), next(nullptr) {}
};
Node* cursor;
std::stack<Node*> st;
bool check[1000005];
void Order(const std::string& order)
{
    int X = order.size() <= 1 ? 0 : std::stoi(order.substr(2));
    if(order[0] == 'U')
    {
        for(int i = 0; i < X; i++)
            cursor = cursor->prev;
    }
    if(order[0] == 'D')
    {
        for(int i = 0; i < X; i++)
            cursor = cursor->next;
    }
    if(order[0] == 'C')
    {   
        check[cursor->idx] = false;
        st.push(cursor);
        Node* prevNode = cursor->prev;
        Node* nextNode = cursor->next;
        if(prevNode)
            prevNode->next = nextNode;
        if(nextNode)
            nextNode->prev = prevNode; 
        cursor = (nextNode) ? nextNode : prevNode;
    }
    if(order[0] == 'Z')
    {
        Node* delNode = st.top();
        check[delNode->idx] = true;
        st.pop();
        if(delNode->prev)
            delNode->prev->next = delNode;
        if(delNode->next)
            delNode->next->prev = delNode;
    }
}

string solution(int n, int k, vector<string> cmd) 
{
    string answer = "";
    
    std::memset(check, true, sizeof(check));
    Node* head = new Node(0);
    Node* temp = head;
    cursor = head;
    for(int i = 1; i < n; i++)
    {
        Node* newNode = new Node(i);
        newNode->prev = temp;
        temp->next = newNode;
        temp = newNode;
        if(i == k)
            cursor = newNode;
        
    }
    for(int i = 0; i < cmd.size(); i++)
        Order(cmd[i]);
   
    while(head)
    {
        Node* nextNode = head->next;
        delete head;
        head = nextNode;
    }
    for(int i = 0; i < n; i++)
        answer += check[i] ? "O" : "X";
  
    return answer;
}