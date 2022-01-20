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
    vector<vector<int>> res, v;
    
    void inorder(TreeNode* node, int depth) {
        if(!node) return;
        maxDepth = max(maxDepth, depth-1);
        
        if( v.size() < depth ) {
            v.push_back({node->val});
        }
        else {
            v[depth-1].push_back(node->val);
        }
        
        inorder(node->left, depth+1);
        inorder(node->right, depth+1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return res;
        inorder(root, 1);
        
        for(int i=maxDepth ; i>=0 ; i--) {
            res.push_back(v[i]);
        }
        
        return res;
    }
};