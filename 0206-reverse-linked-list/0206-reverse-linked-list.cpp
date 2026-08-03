/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(!head) return nullptr;
        auto ret = RecursiveList(head);
        head->next = nullptr;
        return ret;
    }
    ListNode* RecursiveList(ListNode* cur)
    {
        if(!cur->next) return cur;
        auto next = cur->next;
        auto ret = RecursiveList(next);
        next->next = cur;
        return ret;
    }
};