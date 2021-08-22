class Solution {
public:
    int F[31];
    
    int fibonacciGenerator(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        return fibonacciGenerator(n-1) + fibonacciGenerator(n-2);
    }
    
    int fib(int n) {
        F[0] = 0;
        F[1] = 1;
        
        if(n<=1) return F[n];

        return fibonacciGenerator(n);
    }
};