class Solution {
public:
    int hammingWeight(uint32_t n) {
        int hw = 0;
        
        while(n > 0) {
            if(n & 1 == 1) hw++;
            n = n >> 1;
        }
        
        return hw;
    }
};