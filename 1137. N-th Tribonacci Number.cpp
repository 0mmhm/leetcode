class Solution {
public:
    int dp[40];
    
    int tribo(int n) {
        if(dp[n] != -1) return dp[n];
        
        dp[n] = tribo(n-1) + tribo(n-2) + tribo(n-3);
        return dp[n];
    }
    
    int tribonacci(int n) {
        for(int i=0 ; i<=n ; i++) dp[i] = -1;
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        
        return n<3 ? dp[n] : tribo(n);
    }
};