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
    TreeNode* n = NULL;
    int maxDepth = 0, maxCommonDepth = 0;
    
    int findDepth(TreeNode* node, int depth) {
        if(!node) return depth - 1;
        
        int ld, rd;
        ld = rd = -1;
        
        ld = findDepth(node->left, depth + 1);
        rd = findDepth(node->right, depth + 1);
        
        if(ld == rd && ld == -1) {
            if(depth > maxDepth) {
                maxDepth = depth;
                n = node;
                return depth;
            }
        }
        
        if(ld == rd && ld != -1) {
            if(ld >= maxDepth) {
                maxDepth = ld;
                n = node;
                return ld;
            }
        }
        
        return ld > rd ? ld : rd;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        findDepth(root, 0);
        
        return n;
    }
};