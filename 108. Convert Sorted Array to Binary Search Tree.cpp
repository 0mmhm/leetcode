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
    TreeNode* create(int left, int right, vector<int>& v) {
        if(left > right) return NULL;
        
        int mid = (left + right) / 2;
        return new TreeNode(v[mid], create(left, mid-1, v), create(mid+1, right, v));
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        int mid = (0+nums.size()-1) / 2;
        return new TreeNode(nums[mid], create(0, mid-1, nums), create(mid+1, nums.size()-1, nums));
    }
};