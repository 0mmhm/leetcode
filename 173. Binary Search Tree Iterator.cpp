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
class BSTIterator {
public:
    stack<TreeNode*> st;
    
    BSTIterator(TreeNode* root) {
        // st = stack<TreeNode*>();
        // st.empty();
        getsLeft(root);
    }
    
    int next() {
        TreeNode *n = st.top();
        st.pop();
        if(n->right) getsLeft(n->right);
        return n->val;
    }
    
    bool hasNext() {
        if( !st.empty() ) return true;
        return false;
    }
    
    private:
        void getsLeft(TreeNode* node) {
            while(node) {
                st.push(node);
                node = node->left;
            }
        }
};


/*
class BSTIterator {
public:
    vector<int> v;
    int ind, len;
    void inorder(TreeNode* node) {
        if(!node) return;
        
        inorder(node->left);
        v.push_back(node->val);
        inorder(node->right);
    }
    
    BSTIterator(TreeNode* root) {
        v.clear();
        inorder(root);
        
        ind = 0;
        len = v.size();
    }
    
    int next() {
        return v[ind++];
    }
    
    bool hasNext() {
        if(ind<len) return true;
        return false;
    }
};

*/

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */