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
    vector <int> v;
    int x, y;
    
    void traverseTreeInorder(TreeNode* node, bool sign) {
        if( !node ) return;
        
        traverseTreeInorder(node->left, sign);
        
        if( !sign ) v.push_back(node->val);
        else{
            if( node->val == x )
                node->val = y;
            else if( node->val == y )
                node->val = x;
        }
        
        traverseTreeInorder(node->right, sign);
    }
    
    void recoverTree(TreeNode* root) {
        traverseTreeInorder(root, false);
        
        bool found = false;
        x = y = -1;
        int i, len = v.size();
        
        for( i=0 ; i<len-1 ; i++ ) {
            if( v[i] > v[i+1] ) {
                y = v[i+1];
                
                if( !found ) {
                    found = true;
                    x = v[i];
                }
                else 
                    i = len;
            }
        }
        
        traverseTreeInorder(root, true);
    }
};