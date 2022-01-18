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
    
    void createBST(TreeNode* node, int val) {
        if(node == NULL) {
            root = new TreeNode(val);
            return;
        }
        
        if(node->val > val) {
            if(!node->left) {
                node->left = new TreeNode(val);
                return;
            }
            createBST(node->left, val);
        }
        else {
            if(!node->right) {
                node->right = new TreeNode(val);
                return;
            }
            createBST(node->right, val);
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return NULL;
        
        int i, len = preorder.size();
        root = NULL;
        
        for( i=0 ; i<len ; i++ ) {
            createBST(root, preorder[i]);
        }
        
        return root;
    }
};