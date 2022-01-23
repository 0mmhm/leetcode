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
    vector<vector<int>> v;
    vector<int> resList;
    
    void traverseTree(TreeNode* node, int level) {
        if(!node) return;
        
        if(level == v.size()) {
            v.push_back({});
        }
        
        v[level].push_back(node->val);
        traverseTree(node->left, level+1);
        traverseTree(node->right, level+1);
    }
    
    void rightView() {
        int len = v.size();
        for(int i=0 ; i<len ; i++ ) {
            resList.push_back(v[i][v[i].size()-1]);
        }
    }
    
    vector<int> rightSideView(TreeNode* root) {
        traverseTree(root, 0);
        rightView();
        
        return resList;
    }
};