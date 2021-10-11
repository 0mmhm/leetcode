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
    map    <int, int> mp;
    int totalSum = 0;
    
    void traverseTree(TreeNode* node, int functionality) {
        if(node == NULL) return;
        
        if( functionality ) {
            v.push_back(node->val);
            totalSum += node->val;
        }
        else {
            node->val += mp[node->val];
        }
        
        traverseTree(node->left, functionality);
        traverseTree(node->right, functionality);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        traverseTree(root, 1);
        
        sort(v.begin(), v.end());
        
        int i, len = v.size();
        for( i=0 ; i<len ; i++ ) {
            totalSum -= v[i];
            mp[v[i]] = totalSum;
        }
        
        traverseTree(root, 0);
        
        return root;
    }
};