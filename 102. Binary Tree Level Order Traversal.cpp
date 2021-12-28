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
    vector<vector<int>> res;
    int depth;
    
    void traverse(TreeNode* node, int level) {
        if(!node) return;
        if(level > depth){
            depth = level;
            res.push_back({});
        }
        
        res[level].push_back(node->val);
        traverse(node->left, level+1);
        traverse(node->right, level+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        depth = -1;
        res.clear();
        
        traverse(root, 0);
        
        return res;
    }
};