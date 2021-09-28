class Solution {
public:
    int dp[31];
    
    int fibo(int n) {
        if(dp[n] != -1) return dp[n];
        
        dp[n] = fibo(n-1) + fibo(n-2);
        
        return dp[n];
    }
    
    int fib(int n) {
        for(int i=0 ; i<=n ; i++ ) dp[i] = -1;
        dp[0] = 0;
        dp[1] = 1;
        
        return n<2 ? dp[n] : fibo(n);
    }
};