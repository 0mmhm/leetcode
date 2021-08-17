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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oddHead, *oddPrev, *evenHead, *evenPrev, *curr = head;;
        oddHead = oddPrev = evenHead = evenPrev = NULL;
        if(head == NULL) return head;
        
        int i = 0;
        while(curr != NULL) {
            i++;
            if( i%2 ) {       // odd
                if(oddHead == NULL) {
                    oddHead = oddPrev =  curr;
                }
                else {
                    oddPrev->next = curr;
                    oddPrev = curr;
                }
            }
            else {              // even
                if(evenHead == NULL) {
                    evenHead = evenPrev = curr;
                }
                else {
                    evenPrev->next = curr;
                    evenPrev = curr;
                }
            }
            
            curr = curr->next;
        }
        if(evenHead != NULL) oddPrev->next = evenHead;
        if(evenHead != NULL) evenPrev->next = NULL;
        
        return oddHead;
    }
};