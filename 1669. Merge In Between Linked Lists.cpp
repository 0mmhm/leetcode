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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *tempPrev, *prev, *last, *curr = list1, *secListLast = list2;
        
        while(secListLast->next != NULL) secListLast = secListLast->next;
        
        tempPrev = prev = last = NULL;
        
        int i = -1;
        while(curr != NULL) {
            i++;
            if(i == a){
                prev = tempPrev;
            }
            
            if(i == b) {
                last = curr->next;
                break;
            }
            
            tempPrev = curr;
            curr = curr->next;
        }
        
        if(prev == NULL) list1 = list2;
        else {
            prev->next = list2;
        }
        
        if(last == NULL) secListLast = NULL;
        else secListLast->next = last;
        
        return list1;
    }
};