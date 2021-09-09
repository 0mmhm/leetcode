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
    int findDepth(TreeNode* node, int depth) {
        if(node == NULL) return depth - 1;
        
        int left, right;
        left = findDepth(node->left, depth + 1);
        right = findDepth(node->right, depth + 1);
        
        return left > right ? left : right;
    }
    
    int maxDepth(TreeNode* root) {
        return findDepth(root, 1);
    }
};