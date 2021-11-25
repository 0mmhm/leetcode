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
    void recoverTree(TreeNode* root) {
        TreeNode *pNode, *prev = NULL, *x = NULL, *y = NULL, *node = root;
        stack <TreeNode*> st;
        
        while( !st.empty() || node ) {
            while( node ) {
                st.push(node);
                node = node->left;
            }
            
            if( !st.empty() ) {
                node = st.top(); st.pop();
                if( prev && prev->val > node->val ) {
                    y = node;
                    
                    if( !x ) x = prev;
                    else break;
                }
                prev = node;
                node = node->right;
            }
        }
        
        int temp = x->val;
        x->val = y->val;
        y->val = temp;
    }
};