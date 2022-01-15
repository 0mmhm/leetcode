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
    map<TreeNode*, int> mp;
    vector<TreeNode*> m, n;
    bool found;
    
    int find(TreeNode* node, TreeNode* x, vector<TreeNode*>& v) {
        if(!node || found) return 0;
        if(node == x) {
            v.push_back(x);
            return 1;
        }
        int lres = 0, rres = 0;
        lres = find(node->left, x, v);
        rres = find(node->right, x, v);
        
        if(lres || rres) v.push_back(node);
        
        return lres || rres;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
            
        find(root, p, m);
        find(root, q, n);
        
        int len = m.size();
        for(int i=0 ; i<len ; i++ ) {
            mp[m[i]]++;
        }
        
        TreeNode* res = NULL;
        len = n.size();
        for(int i=0 ; i<len ; i++ ) {
            mp[n[i]]++;
            
            if(mp[n[i]] > 1) {
                res = n[i];
                break;
            }
        }
        
        return res;
    }
};