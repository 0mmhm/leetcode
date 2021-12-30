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
    unordered_map<TreeNode*, int> mp;
    TreeNode* LCA = NULL;
    int count = 0;
    
    int findNodePath(TreeNode* node, TreeNode* n) {
        if(!node || LCA) return 0;
        
        if(node == n){
            mp[node]++;
            
            if(mp[node] > 1){
                LCA = node;
                return 0;
            }
            return 1;
        }
        int lres = 0, rres = 0;
        
        lres = findNodePath(node->left, n);
        rres = findNodePath(node->right, n);
        
        if(lres || rres) {
            mp[node]++;
        }
        if(mp[node] > 1){
            LCA = node;
            return 0;
        }
        
        return lres || rres;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        mp.clear();
        
        findNodePath(root, p);
        findNodePath(root, q);
        
        return LCA;
    }
};