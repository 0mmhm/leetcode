class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int i, n = s.length();
        vector<int> p(n+1);
        
        p[0] = 0;
        for( i=1; i<=n ; i++ ) {
            p[i] = p[i-1] + (s[i-1] == '1' ? 1 : 0);
        }
        
        int minFlip = 1000009;
        for( i=0 ; i<=n ; i++ ) {
            minFlip = min(minFlip, p[i] + ((n-i) - (p[n] - p[i])) );
        }
        
        return minFlip;
    }
};