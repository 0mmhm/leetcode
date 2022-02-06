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
    TreeNode* n;
    int maxDepth;
    
    int findDepth(TreeNode* node, int depth) {
        if(!node) return depth - 1;
        
        int ld = 0, rd = 0;
        ld = findDepth(node->left, depth+1);
        rd = findDepth(node->right, depth+1);
        
        if(ld == rd && ld != 0 && ld >= maxDepth) {
            maxDepth = ld;
            n = node;
            return ld;
        }
        
        if(ld == rd && ld == 0){
            if(depth > maxDepth) {
                maxDepth = depth;
                n = node;
            }
            return depth;
        }
        
        return ld > rd ? ld : rd;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        n = root;
        maxDepth = 0;
        findDepth(root, 0);
        
        return n;
    }
};