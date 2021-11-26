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
    bool matchMirror(TreeNode* x, TreeNode* y) {
        if( !x && !y) return true;
        if( (!x && y) || (x && !y) || (x->val != y->val) ) return false;
        
        return matchMirror(x->left, y->right) && matchMirror(x->right, y->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if( !root ) return true;
        return matchMirror(root->left, root->right);
    }
};