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
    TreeNode* root = NULL;
    int ind;
    
    void letsBuildTree(vector<int>& pre, vector<int>& in, int leftIn, int inlen, TreeNode* node, int sub) {
        ind++;
        if(ind >= pre.size()) return;
        
        int i, currRootInd = -1;
        for( i=leftIn ; i<=inlen ; i++ ){
            if(in[i] == pre[ind]) {
                currRootInd = i;
                break;
            }
        }
        if(currRootInd == -1){
            ind--;
            return;
        }
        
        if(!node) {
            node = new TreeNode(pre[ind]);
            root = node;
        }
        else {
            TreeNode* newNode = new TreeNode(pre[ind]);
            if(sub == 0) {
                node->left = newNode;
                node = newNode;
            }
            else {
                node->right = newNode;
                node = newNode;
            }
        }
        
        letsBuildTree(pre, in, leftIn, i-1, node, 0);
        letsBuildTree(pre, in, i+1, inlen, node, 1);
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        ind = -1;
        letsBuildTree(preorder, inorder, 0, inorder.size()-1, NULL, 0);
        
        return root;
    }
};