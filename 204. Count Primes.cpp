class Solution {
public:
    char sieve[5*1000005];
    
    void primeSieve(int n) {
        sieve[0] = sieve[1] = 1;
        int i, j;
        
        for( i=4 ; i<n ; i+=2 ) sieve[i] = 1;
        
        int sqrtn = sqrt(n);
        for( i=3 ; i<=sqrtn ; i+=2) {
            if(sieve[i] == 0) {
                for( j=i*i ; j<n ; j+= 2*i ) sieve[j] = 1;
            }
        }
    } 
    
    int countPrimes(int n) {
        primeSieve(n);
        
        int i, res = 0;
        for( i=2 ; i<n ; i++ ) if(sieve[i] == 0) res++;
        
        return res;
    }
};