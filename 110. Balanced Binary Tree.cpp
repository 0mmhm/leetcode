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
    bool v;
    
    int height(TreeNode* node) {
        if (!node || !v ) return 0;
        
        int left, right;
        left = right = 0;
        left = height(node->left);
        right = height(node->right);
        
        if(abs(left-right) > 1) v = false;
        
        return max(left, right) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        v = true;
        
        height(root);
        
        return v;
    }
};