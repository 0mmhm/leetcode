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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    
    void convertToBST(TreeNode* node, int left, int right, int sub) {
        if(left>right) {
            return;
        }
        
        int mid = (left + right) / 2;
        TreeNode* n = new TreeNode(v[mid]);
        
        if(!sub) node->left = n;
        else node->right = n;
        
        convertToBST(n, left, mid-1, 0);
        convertToBST(n, mid+1, right, 1);
    }
    
    void extractValues(ListNode* node) {
        if(!node) return;
        v.push_back(node->val);
        extractValues(node->next);
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if( !head ) return NULL;
        v.clear();
        extractValues(head);
        
        int len = v.size();
        int mid = (0 + len-1) / 2;
        TreeNode* treeHead = new TreeNode(v[mid]);
        
        convertToBST(treeHead, 0, mid-1, 0);
        convertToBST(treeHead, mid+1, len-1, 1);
        
        cout << treeHead->val << endl;
        
        return treeHead; 
    }
};