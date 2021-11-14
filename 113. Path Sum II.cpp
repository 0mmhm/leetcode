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
    vector <string> list;
    int target;
    
    string convertToString(int num) {
        if(num == 0) return "0";
        
        string path = "";
        int rem;
        if(num < 0) {
            path = "-";
            num *= -1;
        }
        while(num > 0) {
            rem = num % 10;
            num /= 10;
            path += rem + '0';
        }
        return path;
    }
    
    void extractResult(vector <vector<int>> &res) {
        int i, len = list.size();
        
        vector <int> v;
        for( i=0 ; i<len ; i++ ) {
            string str = list[i];
            cout << str << endl;
            int val, k, mul, strLen = str.length();
            
            k = mul = 1;
            val = 0;
            bool isNeg = false;
            
            while(k < strLen) {
                if(str[k] == ' ') {
                    if(isNeg)
                        val *= -1;
                    v.push_back(val);
                    val = 0;
                    mul = 1;
                    isNeg = false;
                }
                else if(str[k] == '-') {
                    isNeg = true;
                }
                else{
                    val = (val) + ((str[k] - '0') * mul);
                    mul *= 10;
                }
                k++;
            }
            
            
            if(isNeg)
                val *= -1;
            
            v.push_back(val);
            res.push_back(v);
            v.clear();
        }
    }
    
    void findSum(TreeNode *node, int sum, string path) {
        if( !node )
            return;
        
        sum += node->val;
        string nodePath = convertToString(node->val);
        path = path + " " + nodePath;
        
        if( sum==target && !node->left && !node->right ) {
            list.push_back(path);
            return;
        }
        
        findSum(node->left, sum, path);
        findSum(node->right, sum, path);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        findSum(root, 0, "");
        
        vector <vector<int>> res;
        
        extractResult(res);
        
        return res;
    }
};