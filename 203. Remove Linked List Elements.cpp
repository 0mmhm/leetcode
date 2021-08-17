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
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL && head->val == val) head = head->next;
        if(head == NULL) return head;
        
        ListNode *prev = head, *garbage, *curr = head->next;
        
        
        while(curr != NULL) {
            if(curr->val == val) {
                while(curr != NULL && curr->val == val) {
                    garbage = curr;
                    curr = curr->next;
                    delete(garbage);
                }
                prev->next = curr;
            }
            prev = curr;
            if(curr != NULL) curr = curr->next;
        }
        return head;
    }
};