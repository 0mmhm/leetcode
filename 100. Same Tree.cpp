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
    bool isSame;
    
    void matchTrees(TreeNode* a, TreeNode* b) {
        if( !a && !b ) return;
        if( (!a && b) || (a && !b) || (a->val != b->val)) {
            isSame = false;
            return;
        }
        
        matchTrees(a->left, b->left);
        matchTrees(a->right, b->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        isSame = true;
        matchTrees(p, q);
        
        return isSame;
    }
};