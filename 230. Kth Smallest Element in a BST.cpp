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
    int ind;
    stack<TreeNode*> st;
    
    int kthSmallest(TreeNode* root, int k) {
        ind = 0;
        TreeNode* n = root;
        
        while(n || !st.empty()) {
            while(n) {
                st.push(n);
                n = n->left;
            }
            
            if(!st.empty()) {
                n = st.top();
                st.pop();
                ind++;
                if(ind == k) return n->val;
                
                n = n->right;
            }
        }
        
        // result will not return 0 anytime. because k<=total_number_of_node
        return 0;
    }
};