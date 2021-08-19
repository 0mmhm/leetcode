class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int res = (nums[len-1] - 1) * (nums[len-2] - 1);
        
        return res; 
    }
};