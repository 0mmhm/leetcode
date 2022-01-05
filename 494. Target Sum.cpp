class Solution {
public:
    
    int findWays(vector<int>& v, int ind, int sum, int target, int total, vector<vector<int>>& dp) {
        if(ind == v.size()) {
            if(sum == target) return 1;
            return 0;
        }
        
        if(dp[ind][total+sum] != -1) return dp[ind][total+sum];
        
        int left, right;
        left = findWays(v, ind+1, sum+v[ind], target, total, dp);
        right = findWays(v, ind+1, sum-v[ind], target, total, dp);
        dp[ind][sum+total] = left + right;
        
        return left + right;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int i, j, len = nums.size(), total = 0;
        
        for( i=0 ; i<len ; i++ ) total += nums[i];
        
        vector<vector<int>> dp(len, vector<int>(total*2+1));
        
        for( i=0 ; i<len ; i++ ){
            for( j=0 ; j<total*2+1 ; j++ ) dp[i][j] = -1;
        }
        
        return findWays(nums, 0, 0, target, total, dp);
    }
};