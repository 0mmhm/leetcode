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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next == NULL || left == right) return head;
        
        ListNode *leftN, *rightN, *leftPrev, *rightAfter, *nextN, *curr, *prev;
        curr = head;
        
        left--;
        right--;
        if(left == 0) head = NULL;
        
        leftN = rightN = leftPrev = rightAfter = prev = NULL;
        int i = -1;
        while(curr != NULL){
            i++;
            if(i==left-1){
                leftPrev = curr;
            }
            else if(i==left){
                leftN = curr;
            }
            else if(i==right){
                rightN = curr;
            }
            else if(i == right+1){ 
                rightAfter = curr; 
                break; 
            }
            
            if(i>=left && i<=right){
                nextN = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextN;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        
        if(leftPrev != NULL){
            leftPrev->next = rightN;
        }
        else{
            head = rightN;
        }
        if(rightAfter != NULL){
            leftN->next = rightAfter;
        }
        else{
            leftN->next = NULL;
        }
        
        return head;
        
    }
};