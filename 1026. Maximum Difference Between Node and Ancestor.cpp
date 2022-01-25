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
    
    int maxDifference(TreeNode* node, int large, int small) {
        if(!node) return large - small;
        
        int left, right;
        left = maxDifference(node->left, max(node->val, large), min(node->val, small));
        right = maxDifference(node->right, max(node->val, large), min(node->val, small));
        
        return max(left, right);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        return maxDifference(root, root->val, root->val);
    }
};