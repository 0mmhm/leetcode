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
    stack<TreeNode*> m, n;
    vector<int> v;
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        m.empty();
        n.empty();
        
        while(root1 || root2 || !m.empty() || !n.empty()) {
            while(root1) {
                m.push(root1);
                root1 = root1->left;
            }
            
            while(root2) {
                n.push(root2);
                root2 = root2->left;
            }
            
            
            if( n.empty() || (!m.empty() && m.top()->val <= n.top()->val)) {
                v.push_back(m.top()->val);
                root1 = m.top();
                m.pop();
                root1 = root1->right;
            }
            else{
                v.push_back(n.top()->val);
                root2 = n.top();
                n.pop();
                root2 = root2->right;
            }
        }
        
        return v;
    }
};