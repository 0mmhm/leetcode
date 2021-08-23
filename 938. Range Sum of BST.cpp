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
    int n, m;
    
    int findSum(TreeNode *node) {
        if(node == NULL) return 0;
        int value, rootVal;
        value = rootVal = 0;
        value = node->val;
        if(value >= n && value <= m) rootVal = value;
        
        int left = 0, right = 0;
        if(node->left != NULL) left = findSum(node->left);
        if(node->right != NULL) right = findSum(node->right);
        
        return rootVal + left + right;   
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        n = low; m = high;
        return findSum(root);
    }
};
