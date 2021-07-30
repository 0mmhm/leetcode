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
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *currNext, *curr = head;
        int comp;
        while(curr->next != NULL){
            comp = curr->val;
            currNext = curr;
            while( currNext->next->val == comp){
                currNext = currNext->next;
                if(currNext->next == NULL) break;
            }
            
            if(currNext->next != NULL){
                currNext = currNext->next;
                curr->next = currNext;
                curr = currNext;
            }
            else curr->next = NULL;
        }
        return head;
    }
};