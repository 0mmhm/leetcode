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
    void reorderList(ListNode* head) {
        ListNode *temp, *curr = head;
        
        temp = new ListNode(head->val);
        curr = curr->next;
        int len = 1;
        while(curr != NULL){
            len++;
            ListNode* node = new ListNode(curr->val);
            node->next = temp;
            temp = node;
            curr = curr->next;
        }
        
        curr = head;
        ListNode *a, *b;
        int i = 1;
        while(i<len) {
            if(i%2) {
                a = curr->next;
                curr->next = temp;
                curr = a;
            }
            else {
                b = temp->next;
                temp->next = curr;
                temp = b;
            }
            i++;
        }
        temp->next = NULL;
        curr->next = NULL;
        
    }
};