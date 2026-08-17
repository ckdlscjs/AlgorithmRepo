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
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = head->next, *largest = head;
        dummy->next = head;
        while(cur)
        {
            if(cur->val >= largest->val)
            {
                largest = cur;
                cur = cur->next;
            }
            else
            {
                ListNode* temp = dummy;
                while(temp && temp->next->val <= cur->val)
                    temp = temp->next;
                largest->next = cur->next;
                cur->next = temp->next;
                temp->next = cur;
                cur = largest->next;
            }
        }
        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
};