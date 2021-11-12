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
    bool isValid;
    
    void traverseTreeInorder(TreeNode *node, vector<int> &v) {
        if( !node )
            return;
        
        if(node->left)
            traverseTreeInorder(node->left, v);
        
        v.push_back(node->val);
        
        if(node->right)
            traverseTreeInorder(node->right, v);
    }
    
    bool isValidBST(TreeNode* root) {
        isValid = true;
        vector <int> v;
        
        traverseTreeInorder(root, v);
        
        int len = v.size();
        
        for(int i=0 ; i<len-1 ; i++ ) {
            if( v[i] >= v[i+1] ) {
                isValid = false;
                break;
            }
        }
        
        return isValid;
    }
};