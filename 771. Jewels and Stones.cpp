class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map <char, int> mp;
        mp.clear();
        
        int jlen = jewels.length();
        int slen = stones.length();
        
        int i;
        for( i=0 ; i<jlen ; i++ ){
            mp[ jewels[i] ] = 1;
        }
        
        int res = 0;
        for( i=0 ; i<slen ; i++ ){
            res += mp[ stones[i] ];
        }
        
        return res;
    }
};