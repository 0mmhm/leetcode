class Solution {
public:
    vector<int> fib;
    int target;
    
    void genFib() {
        int i;
        fib.push_back(1);
        fib.push_back(1);
        
        i = 1;
        while( fib[i] < target ) {
            i++;
            int fibo = fib[i-1] + fib[i-2];
            fib.push_back(fibo);
        }
    }
    
    int findMinFibonacciNumbers(int k) {
        target = k;
        genFib();
        
        int i, j = fib.size() - 1, res = 0;
        while( j >= 0) {
            if(fib[j] <= k) {
                k -= fib[j];
                res++;
            }
            j--;
            
            if(k == 0) break;
        }
        
        return res;
    }
};