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
    bool resulttOfFindings;
    int myTargetSum;
    
    void findTargetSum(TreeNode* node, int sum) {
        if( resulttOfFindings ) return;
        if(node == NULL) return;
        
        sum += node->val;
        
        if(node->left == NULL && node->right == NULL) {
            if(sum == myTargetSum) resulttOfFindings = true;
            return;
        }
        
        findTargetSum(node->left, sum);
        findTargetSum(node->right, sum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        resulttOfFindings = false;
        myTargetSum = targetSum;
        
        findTargetSum(root, 0);
        
        return resulttOfFindings;
    }
};