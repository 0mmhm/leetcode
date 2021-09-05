class Solution {
public:
    bool isPowerOfFour(int n) {
        if( n < 1 || n == 2 || n==3) return false;
        if(n == 1 || n==4) return true;
        
        while(n>4) {
            if(n%4 != 0) return false;
            n /= 4;
        }
        
        if(n == 4) return true;
        else return false;
    }
};