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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *curr = head, *prev = NULL, *nHead = NULL, *Next;
        
        while(curr != NULL){
            Next = curr->next;
            
            curr->next = prev;
            nHead = curr;
            prev = curr;
            curr = Next;
        }
        return nHead;
    }
};