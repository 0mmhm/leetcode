class Solution {
public:
    vector<int> countBits(int n) {
        int i, j, k;
        vector <int> res;
        
        for( i=0 ; i<=n ; i++ ) {
            j = i;
            int tot = 0;
            while(j > 0) {
                k = j & 1;
                if(k == 1) tot++;
                j = j >> 1;
            }
            
            res.push_back(tot);
        }
        return res;
    }
};