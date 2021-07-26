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
    bool hasCycle(ListNode *head) {
        ListNode *temp, *curr = head;
        
        while(curr != NULL){
            if(curr->val > 100009) return true;
            curr->val = 1000099;
            curr = curr->next;
        }
        
        return false;
    }
};