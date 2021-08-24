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
    
    int maxDepth = 0;
    int resSum = 0;
    
    void findDeepestLeavesSum(TreeNode* node, int depth) {
        if(depth > maxDepth) maxDepth = depth;
        if(depth == maxDepth) resSum += node->val;
        
        if(node->left != NULL) findDeepestLeavesSum(node->left, depth + 1);
        if(node->right != NULL) findDeepestLeavesSum(node->right, depth + 1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL) return 0;
        findDeepestLeavesSum(root, 0);
        
        resSum = 0;
        findDeepestLeavesSum(root, 0);
        
        return resSum;
    }
};