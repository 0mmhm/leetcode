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
    
    TreeNode* resNode = NULL;
    
    void targetOnCloned(TreeNode* cloned, TreeNode* target) {
        if(cloned == NULL) return;
        if(cloned->val == target->val) {
            resNode = cloned;
            return;
        }
        
        targetOnCloned(cloned->left, target);
        targetOnCloned(cloned->right, target);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        targetOnCloned(cloned, target);
        
        return resNode;
    }
};