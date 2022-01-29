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
    
    void mergeSort(int temp[], int lo, int hi) {
        if(lo == hi) return;
        
        int mid = (lo + hi) / 2;
        
        mergeSort(temp, lo, mid);
        mergeSort(temp, mid+1, hi);
        
        int i = lo, j = mid+1, k = lo;
        while(i<=mid && j<=hi) {
            if(v[i] <= v[j]) temp[k++] = v[i++];
            else temp[k++] = v[j++];
        }
        
        while(i<=mid) temp[k++] = v[i++];
        while(j<=hi) temp[k++] = v[j++];
        
        for( i=lo ; i<=hi ; i++ ) v[i] = temp[i];
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head) return NULL;
        
        ListNode* curr = head;
        while(curr) {
            v.push_back(curr->val);
            curr = curr->next;
        }
        
        int len = v.size();
        int temp[len];
        
        mergeSort(temp, 0, len-1);
        
        curr = head;
        int i = 0;
        while(curr) {
            curr->val = v[i++];
            curr = curr->next;
        }
        
        return head;
    }
};