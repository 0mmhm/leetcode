class Solution {
public:
    int findClimbingWay(int step, vector<int> &dp) {
        if(step == 1) return 1;
        if(step == 2) return 2;
        
        if(dp[step] != -1)
            return dp[step];
        
        dp[step] = findClimbingWay(step - 1, dp) + findClimbingWay(step - 2, dp);
        return dp[step];
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1, -1); 
    
        return findClimbingWay(n, dp);
    }
};