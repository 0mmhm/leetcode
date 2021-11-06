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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head, *temp;
        
        while(curr) {
            temp = curr;
            while(curr->next && temp->val == curr->next->val) {
                curr = curr->next;
            }
            temp->next = curr->next;
            curr = curr->next;
        }
        return head;
    }
};