class Solution {
public:
    int len, maxAmount = 0, dp[109];
    
    void letsRob(vector<int>& v, int ind, int sum) {
        if(ind >= len){
            maxAmount = max(maxAmount, sum);
            return;
        }      
        
        if(dp[ind] == -1 || dp[ind] < sum+v[ind]) {
            dp[ind] = sum + v[ind];
            letsRob(v, ind+2, sum+v[ind]);
        }

        letsRob(v, ind+1, sum);
    }
    
    int rob(vector<int>& nums) {
        len = nums.size();
        for(int i=0 ; i<len ; i++ ) dp[i] = -1;
        
        letsRob(nums, 2, nums[0]);
        if(len>1) letsRob(nums, 1, 0);
        
        return maxAmount;
    }
};