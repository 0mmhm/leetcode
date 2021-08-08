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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *res = NULL, *curr = headA;
        while(curr != NULL){
            curr->val = curr->val * -1;
            curr = curr->next;
        }
        
        curr = headB;
        while(curr != NULL){
            if(curr->val < 0){
                res = curr;
                break;
            }
            curr = curr->next;
        }
        
        curr = headA;
        while(curr != NULL){
            curr->val = curr->val * -1;
            curr = curr->next;
        }
        
        return res;
    }
};