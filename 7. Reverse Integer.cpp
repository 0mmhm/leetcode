class Solution {
public:
    int reverse(int x) {
        int negetiveMax = -2147483648, positiveMax = 2147483647;
        
        int rev = 0, modVal;
        
        while(x != 0) {
            modVal = x % 10; x /= 10;
            if(rev > positiveMax/10 || (rev == positiveMax/10 && modVal > 7)) {
                rev = 0;
                break;
            }
            else if(rev < negetiveMax/10 || (rev == negetiveMax/10 && modVal < -8)) {
                rev = 0;
                break;
            }
            
            rev = (rev * 10) + modVal;
        }
        
        return rev;
    }
};