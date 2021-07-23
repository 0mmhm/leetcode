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
        ListNode *curr = head, *prev = NULL;
        bool headFound = false;
        head = NULL;
        while(curr != NULL) {
            if(curr->next != NULL && curr->val == curr->next->val){
                int temp = curr->val;
                while(curr != NULL && curr->val == temp){
                    curr = curr->next;
                }
            }
            else{
                if(!headFound){
                    headFound = true;
                    head = curr;
                }
                if(prev != NULL) prev->next = curr;
                prev = curr;
                curr = curr->next;
            }
        }
        if(prev != NULL) prev->next = NULL;
        return head;
    }
};