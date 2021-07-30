/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* curr = head;
        if( curr == NULL || curr->next == NULL) return NULL;
        
        while(curr != NULL) {
            if( curr->val > 100009) return curr;
            curr->val = 1000099;
            curr = curr->next;
        }
        return NULL;
    }
};