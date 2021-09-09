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
    vector<int> v;
    int len;
    TreeNode* prev = NULL;
    
    void traverseTree(TreeNode* node) {
        if(node == NULL) return;
        
        v.push_back(node->val);
        traverseTree(node->left);
        traverseTree(node->right);
    }
    
    void genTree(int ind) {
        if(ind < len) {
            TreeNode* n = new TreeNode(v[ind]);
            n->left = NULL;
            n->right = NULL;
            prev->right = n;
            prev = n;
            genTree(ind + 1);
        }
    }
    
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        
        traverseTree(root);
        
        len = v.size();
        
        root->left = root->right = NULL;
        prev = root;
        genTree(1);
        
    }
};