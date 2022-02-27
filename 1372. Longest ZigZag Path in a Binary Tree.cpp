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
    int longest;
    
    void findLongestZigZag(TreeNode* node, int len, int dir) {
        if(!node) return;
        
        longest = max(longest, len);
        
        // dir = 1 means prev dir was left, otherwise prev dir was right
        if(dir == 1) {
            findLongestZigZag(node->right, len+1, 2);
            findLongestZigZag(node->left, 1, 1);
        }
        else {
            findLongestZigZag(node->left, len+1, 1);
            findLongestZigZag(node->right, 1, 2);
        }
    }
    
    int longestZigZag(TreeNode* root) {
        longest = 0;
        findLongestZigZag(root, 0, 0);
        
        return longest;
    }
};