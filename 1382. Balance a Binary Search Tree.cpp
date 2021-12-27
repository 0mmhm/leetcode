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
    vector<int> vin;
    
    void inorderTraversal(TreeNode* node) {
        if(!node) return;
        
        inorderTraversal(node->left);
        vin.push_back(node->val);
        inorderTraversal(node->right);
    }
    
    void constructBST(int l, int r, TreeNode* root, int mark) {
       if(l>r) return;
        
        int mid = (l+r) / 2;
        TreeNode* node = new TreeNode(vin[mid]);
        if(!mark) {
            root->left = node;
        }
        else {
            root->right = node;
        }
        
        constructBST(l, mid-1, node, 0);
        constructBST(mid+1, r, node, 1);
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vin.clear();
        inorderTraversal(root);
        
        int len = vin.size();
        int mid = len/2;
        
        TreeNode* newRoot = new TreeNode(vin[mid]);
        
        constructBST(0, mid-1, newRoot, 0);
        constructBST(mid+1, len-1, newRoot, 1);
        
        return newRoot;
    }
};