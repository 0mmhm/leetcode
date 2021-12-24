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
    int goodNodeCount;
    
    void findGoodNodes(TreeNode* node) {
        if( !node ) return;
        
        if(node->left) {
            if(node->left->val >= node->val) goodNodeCount++;
            
            node->left->val = max(node->left->val, node->val);
            findGoodNodes(node->left);
        }
        if(node->right) {
            if(node->right->val >= node->val) goodNodeCount++;
            
            node->right->val = max(node->right->val, node->val);
            findGoodNodes(node->right);
        }
    }
    
    int goodNodes(TreeNode* root) {
        goodNodeCount = 1;
        findGoodNodes(root);
        
        return goodNodeCount;
    }
};