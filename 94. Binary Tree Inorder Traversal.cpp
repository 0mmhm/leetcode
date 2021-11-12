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
    void inorderTreeTraversal(TreeNode* node, vector <int>&res) {
        if(node->left) {
            inorderTreeTraversal(node->left, res);
        }
        
        res.push_back(node->val);
        
        if(node->right) {
            inorderTreeTraversal(node->right, res);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector <int> res;
        inorderTreeTraversal(root, res);
        
        return res;
    }
};