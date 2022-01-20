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
    TreeNode* root;

    
    void mergeTree(TreeNode* n, int sub, TreeNode* a, TreeNode* b) {
        if(!a && !b) return;
        
        if(a && b) {
            a->val += b->val;
            mergeTree(a, 0, a->left, b->left);
            mergeTree(a, 1, a->right, b->right);
        }
        else if(a && !b) {
            mergeTree(a, 0, a->left, NULL);
            mergeTree(a, 1, a->right, NULL);
        }
        else {
            a = new TreeNode(0);
            if(!n) {
                root = n = a;
            }
            
            if(a!=n && !sub) n->left = a;
            else if(a!=n) n->right = a;
            
            a->val += b->val;
            mergeTree(a, 0, a->left, b->left);
            mergeTree(a, 1, a->right, b->right);
        }
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        root = root1;
        mergeTree(root, 0, root1, root2);
        
        return root;
    }
};