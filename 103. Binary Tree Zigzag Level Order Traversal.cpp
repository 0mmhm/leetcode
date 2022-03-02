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
    vector<vector<int>> v;
    int d = -1;
    
    void traverseTree(TreeNode* node, int depth) {
        if(!node) return;
        
        if(depth > d) {
            d = depth;
            v.push_back({});
        }
        
        v[depth].push_back(node->val);
        traverseTree(node->left, depth+1);
        traverseTree(node->right, depth+1);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        traverseTree(root, 0);    
        
        int i, j, temp, n, m = v.size();
        for( i=0 ; i<m ; i++ ) {
            if(i%2) {
                j = 0;
                n = v[i].size() - 1;
                while(j < n) {
                    temp = v[i][j];
                    v[i][j] = v[i][n];
                    v[i][n] = temp;
                    j++;
                    n--;
                }
            }
        }
        
        return v;
    }
};