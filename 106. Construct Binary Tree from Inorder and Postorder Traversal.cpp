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
    map<int, int> mp;
    int ind;
    
    TreeNode* create(vector<int>& in, vector<int>& post, int left, int right) {
        if(left > right) return NULL;
        
        int rval = post[ind--];
        int rind = mp[rval];
        
        TreeNode* root = new TreeNode(rval);
        
        root->right = create(in, post, rind+1, right);
        root->left = create(in, post, left, rind-1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i, len = inorder.size();
        if(len == 0) return NULL;
        
        for( i=0 ; i<len ; i++ ) mp[inorder[i]] = i;
        ind = len-1;
        return create(inorder, postorder, 0, inorder.size()-1);
    }
};