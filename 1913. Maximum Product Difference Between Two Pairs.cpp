class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int len = nums.size();
        int maxDifference = (nums[len-1] * nums[len-2]) - (nums[1] * nums[0]);
        
        return maxDifference;
    }
};