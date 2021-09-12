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
    int numComponents(ListNode* head, vector<int>& nums) {
        int len = nums.size();
        map <int, int> mp;
        mp.clear();
        for(int i=0 ; i<len ; i++ ) mp[ nums[i] ] = 1;
        
        ListNode* curr = head;
        int compo = 0;
        
        int val, count = 0;
        while(curr != NULL) {
            val = curr->val;
            if( mp[val] == 1 ){
                count++;
                mp[val] = 0;
            }
            else{
                if(count > 0){
                    compo++;
                    count = 0;
                }
            }
            
            curr = curr->next;
        }
        
        if(count > 0) compo++;
        
        return compo;
    }
};