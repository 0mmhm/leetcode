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
    int rtlSum;
    
    void findRTLSum(TreeNode *node, int totVal) {
        if(node->left == NULL && node->right == NULL) {
            totVal = (totVal * 10) + node->val;
            rtlSum += totVal;
            return;
        }
        
        if(node->left) {
            findRTLSum(node->left , (totVal * 10) + node->val);
        }
        
        if(node->right) {
            findRTLSum(node->right, (totVal * 10) + node->val);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        rtlSum = 0;
        findRTLSum(root, 0);
        
        return rtlSum;
    }
};