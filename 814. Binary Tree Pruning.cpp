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
    int pruneSubTree(TreeNode* node) {
        if ( !node ) return 0;
        
        int left, right;
        left = right = 0;
        if( node->left ) left = pruneSubTree(node->left);
        if( node->right ) right = pruneSubTree(node->right);
        
        if(  node->left && !left ){
            delete(node->left);
            node->left = NULL;
        }
        if( node->right && !right ){
            delete(node->right);
            node->right = NULL;
        }
        
        return node->val + left + right;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        int val = pruneSubTree(root);
        if(!val ) {
            delete(root);
            return NULL;
        }
        
        return root;
    }
};