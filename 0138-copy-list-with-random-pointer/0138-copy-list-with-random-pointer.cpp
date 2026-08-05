/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;
        int i = 0;
        std::unordered_map<Node*, int> nodes;
        std::unordered_map<int, Node*> newNodes;
        while(cur)
        {
            nodes[cur] = i;
            newNodes[i++] = new Node(cur->val);
            cur = cur->next;
        }

        for(const auto& iter : nodes)
        {
            if(iter.first->next)
                newNodes[iter.second]->next = newNodes[nodes[iter.first->next]];
            if(iter.first->random)
                newNodes[iter.second]->random = newNodes[nodes[iter.first->random]];
        }
        return newNodes[0];
    }
};