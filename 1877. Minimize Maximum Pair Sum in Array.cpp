class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i, j, maxSum = 0, len = nums.size();
        
        i = len/2 - 1;
        j = i+1;
        
        while(i>=0) {
            maxSum = max(maxSum, nums[i]+nums[j]);
            i--;
            j++;
        }
        
        return maxSum;
    }
};