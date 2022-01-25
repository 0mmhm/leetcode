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
    unordered_map<int, int> mp;
    TreeNode* root;
    
    int findLargest(int x, int y, vector<int>& v) {
        int num = -1, ind = -1;
        for(int i=x ; i<=y ; i++ ) {
            if(v[i] > num) {
                num = v[i];
                ind = i;
            }
        }
        
        return ind;
    }
    
    TreeNode* createTree(int l, int r, vector<int>& v) {
        if(l>r) return NULL;
        
        int getInd = findLargest(l, r, v);
        TreeNode* n = new TreeNode(v[getInd]);
        
        n->left = createTree(l, getInd-1, v);
        n->right = createTree(getInd+1, r, v);
        
        if(!root) root = n;
        
        return n;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int len = nums.size();
        
        root = NULL;
        return createTree(0, len-1, nums);
    }
};