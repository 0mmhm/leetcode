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
    bool found;
    vector<int> v;
    
    void inorder(TreeNode* node, int key) {
        if(!node) return;
        
        inorder(node->left, key);
        if(node->val != key) v.push_back(node->val);
        else found = true;
        inorder(node->right, key);
    }
    
    TreeNode* create(int l, int r) {
        if(l > r) return NULL;
        
        int mid = (l+r) / 2;
        return new TreeNode(v[mid], create(l, mid-1), create(mid+1, r));
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        found = false;
        inorder(root, key);
        if(!found || !root) return root;
        if(v.size() == 0) return NULL;
        
        int mid, len = v.size();
        mid = (0+len-1) / 2;
        return new TreeNode(v[mid], create(0, mid-1), create(mid+1, len-1));
    }
};