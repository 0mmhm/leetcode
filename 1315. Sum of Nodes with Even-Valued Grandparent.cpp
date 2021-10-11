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
    int findSumEvenGrandParent(TreeNode* node, int par, int grandPar) {
        if(node == NULL) return 0;
        
        int value;
        value = grandPar ? node->val : 0;
        
        grandPar = par;
        par = node->val % 2 == 0 ? 1 : 0;
        
        return value + findSumEvenGrandParent(node->left, par, grandPar) 
               + findSumEvenGrandParent(node->right, par, grandPar);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        int rootMark = root->val % 2 == 0 ?  1 : 0;
        return findSumEvenGrandParent(root->left, rootMark, 0)
               + findSumEvenGrandParent(root->right, rootMark, 0);
    }
};