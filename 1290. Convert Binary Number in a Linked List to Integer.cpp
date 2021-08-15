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
    int getDecimalValue(ListNode* head) {
        int i = -1;
        ListNode *curr = head;
        
        while(curr != NULL) {
            i++;
            curr = curr->next;
        }
        
        int res = 0;
        curr = head;
        while(curr != NULL) {
            if(curr->val == 1) res += (1 << i);
            i--;
            curr = curr->next;
        }
        
        return res;
    }
};