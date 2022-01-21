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
    TreeNode* n;
    
    void search(TreeNode* node, int val) {
        if(!node || n) return;
        
        if(node->val == val) {
            n = node;
            return;
        }
        
        search(node->left, val);
        search(node->right, val);
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        n = NULL;
        search(root, val);
        
        return n;
    }
};