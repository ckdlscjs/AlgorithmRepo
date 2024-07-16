#include <bits/stdc++.h>
using namespace std;

struct Node {
    int idx;
    Node* prev;
    Node* next;
    Node(int _idx) : idx(_idx), prev(nullptr), next(nullptr) {}
};

Node* cursor;
std::stack<Node*> st;
bool check[1000005];

void Order(const std::string& order) {
    int X = order.size() <= 1 ? 0 : std::stoi(order.substr(2));
    if (order[0] == 'U') {
        for (int i = 0; i < X; i++) {
            cursor = cursor->prev;
        }
    } else if (order[0] == 'D') {
        for (int i = 0; i < X; i++) {
            cursor = cursor->next;
        }
    } else if (order[0] == 'C') {
        st.push(cursor);
        Node* prevNode = cursor->prev;
        Node* nextNode = cursor->next;
        if (prevNode) {
            prevNode->next = nextNode;
        }
        if (nextNode) {
            nextNode->prev = prevNode;
        }
        check[cursor->idx] = false;
        cursor = (nextNode) ? nextNode : prevNode;
    } else if (order[0] == 'Z') {
        Node* delNode = st.top();
        st.pop();
        if (delNode->prev) {
            delNode->prev->next = delNode;
        }
        if (delNode->next) {
            delNode->next->prev = delNode;
        }
        check[delNode->idx] = true;
    }
}

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'X');
    
    Node* head = new Node(0);
    Node* temp = head;
    cursor = head;

    for (int i = 1; i < n; i++) {
        Node* newNode = new Node(i);
        newNode->prev = temp;
        temp->next = newNode;
        temp = newNode;
        if (i == k) {
            cursor = newNode;
        }
    }

    for (int i = 0; i < n; i++) {
        check[i] = true;
    }

    for (const auto& c : cmd) {
        Order(c);
    }

    for (int i = 0; i < n; i++) {
        if (check[i]) {
            answer[i] = 'O';
        }
    }

    // 메모리 해제
    temp = head;
    while (temp != nullptr) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return answer;
}
