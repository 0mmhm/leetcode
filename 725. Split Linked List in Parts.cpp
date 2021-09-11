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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* curr = head;
        
        while(curr != NULL){
            len++;
            curr = curr->next;
        }
        
        vector<ListNode*> v;
        int count = 0, done = 0, size, extra = 0;
        if( len < k ) len = k;
        size = len / k;
        if(len % k != 0 ) {
            extra = len % k;
        }
        curr = head;
        ListNode *tempHead = NULL, *nextCurr = NULL;
        
        bool e = true;
        if(extra > 0) {
            size++;
            extra--;
        }
        else e = false;
        
        cout << size << endl;
        while(curr != NULL) {
            count++;
            if(tempHead == NULL) {
                tempHead = curr;
            }
            
            if(count == size) {
                v.push_back(tempHead);
                if(curr->next != NULL) nextCurr = curr->next;
                curr->next = NULL;
                curr = nextCurr;
                nextCurr = NULL;
                tempHead = NULL;
                count = 0;
                done++;
                
                if(e) {
                    if(extra > 0) {
                        extra--;
                    }
                    else {
                        e = false;
                        size--;
                    }
                }
                
                continue;
            }
            curr = curr->next;
        }
        
        if(count > 0) {
            v.push_back(tempHead);
            done++;
        }
        
        while(done < k){
            v.push_back(NULL);
            done++;
        }
        
        return v;
        
    }
};