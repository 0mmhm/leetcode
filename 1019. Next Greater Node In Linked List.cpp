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
    vector<int> nextLargerNodes(ListNode* head) {
        int temp, len = 0;
        vector<int> v;
        while(head != NULL) {
            len++;
            v.push_back(head->val);
            head = head->next;
        }
        
        stack<int> st;
        
        st.push(v[len-1]);
        int maxVal = v[len-1];
        v[len-1] = 0;
        for(int i=len-2 ; i>=0 ; i-- ) {
            if( v[i] < maxVal ) {
                while(!st.empty() && st.top() <= v[i]) st.pop();
                temp = v[i];
                v[i] = st.top();
                
            }
            else if(v[i] >= maxVal) {
                maxVal = v[i];
                temp = v[i];
                v[i] = 0;
                st.empty();
            }
            
            st.push(temp);
        }
        
        return v;
    }
};