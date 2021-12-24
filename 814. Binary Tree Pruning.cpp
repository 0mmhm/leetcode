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
    bool pruneSubTree(TreeNode* node) {
        if ( !node ) return false;
        
        bool left, right;
        left = right = false;
        
        if( node->left ) left = pruneSubTree(node->left);
        if( node->right ) right = pruneSubTree(node->right);
        
        if( !left ) node->left = NULL;
        if( !right ) node->right = NULL;
        
        
        return node->val || left || right;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        return pruneSubTree(root) ? root : NULL;
    }
};