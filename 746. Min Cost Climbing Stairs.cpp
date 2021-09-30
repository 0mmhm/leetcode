class Solution {
public:
    void findMinCost(vector<int> &dp, vector<int> &cost, int ind) {
        if( ind < 0 ) return;
        
        if(dp[ind] != -1) 
            return;
        
        dp[ind] = cost[ind] + min(dp[ind+1], dp[ind+2] );
        findMinCost(dp, cost, ind-1);
        return;
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector<int> dp(len, -1);
        dp[len-1] = cost[len-1];
        dp[len-2] = cost[len-2];
        
        findMinCost(dp, cost, len-3);
        
        return dp[0] < dp[1] ? dp[0] : dp[1];
    }
};