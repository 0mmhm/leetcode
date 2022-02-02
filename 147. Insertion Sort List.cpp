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
    vector<int> v;
    
    ListNode* insertionSortList(ListNode* head) {
        ListNode *pNode, *temp, *pre, *n, *curr = head;
        
        int i = -1, j;
        while(curr) {
            v.push_back(curr->val);
            curr = curr->next;
        }
        
        int len = v.size();
        for( i=0 ; i<len ; i++ ) {
            for( j=i-1 ; j>=0 ; j-- ) {
                if( v[j+1] < v[j] ) {
                    int temp = v[j+1];
                    v[j+1] = v[j];
                    v[j] = temp;
                }
            }
        }
        
        curr = head;
        i = 0;
        while(curr) {
            curr->val = v[i++];
            curr = curr->next;
        }
        
        return head;
    }
};