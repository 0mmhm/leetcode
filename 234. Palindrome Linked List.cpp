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
    bool isPalindrome(ListNode* head) {
        string str = "";
        int len = 0;
        
        while( head != NULL) {
            len++;
            str += (head->val) + '0';
            head = head->next;
        }
        
        int i=0, j = len - 1;
        
        while( i<=j ) {
            if( str[i] != str[j]) return false;
            i++;
            j--;
        }
        
        return true;
    }
};