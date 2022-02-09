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
    int sum = 0;
    
    void convertToDecimal(string str) {
        int i, val = 0, num = 1, len = str.length();
        for( i=len-1 ; i>=0 ; i-- ) {
            if(str[i] == '1') val += num;
            num *= 2;
        }
        sum += val;
        
    }
    
    void generateSum(TreeNode* node, string binary) {
        if(!node) return;
        
        binary += to_string(node->val);
        if(!node->left && !node->right) {
            convertToDecimal(binary);
            return;
        }
        
        generateSum(node->left, binary);
        generateSum(node->right, binary);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        sum = 0;
        generateSum(root, "");
        
        return sum;
    }
};