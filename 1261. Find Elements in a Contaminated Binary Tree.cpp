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
class FindElements {
public:
    unordered_map<int, bool> mp;
    
    void restoreTree(TreeNode *n, int val) {
        if(n) {
            n->val = val;
            mp[val] = true;
            if(n->left) {}
                restoreTree(n->left, 2*val+1);
            if(n->right)
                restoreTree(n->right, 2*val+2);
        }
    }
    
    FindElements(TreeNode* root) {
        mp.clear();
        
        restoreTree(root, 0);
    }
    
    bool find(int target) {
        if(mp[target])
            return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */