/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool found = false;
    TreeNode *successor = NULL;

    void traverse(TreeNode* node, TreeNode* p) {
        if(found || !node) return;
        traverse(node->left, p);
        
        if(!found && node->val > p->val) {
            successor = node;
            found = true;
        }
        
        traverse(node->right, p);
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        traverse(root, p);
        
        return successor;
    }
};
/*
class Solution {
public:
    map<TreeNode*, TreeNode*> mp;
    
    TreeNode* successor(TreeNode* p) {
        if(p->right) {
            p = p->right;
            while(p->left) p = p->left;
            return p;
        }
        else if(mp[p]) {
            int currVal = p->val;    
            p = mp[p];
            while(p->val < currVal && mp[p]) p = mp[p];
            if(p->val < currVal && !mp[p]) return NULL;
            return p;
        }
        
        return NULL;
    }
    
    void traverse(TreeNode* par, TreeNode* node) {
        if(!node) return;
        
        traverse(node, node->left);
        mp[node] = par;
        traverse(node, node->right);
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        traverse(NULL, root);
        
        return successor(p);
    }
};
*/