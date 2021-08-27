class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int w = -1;
        int i, j, sum, n, m = accounts.size();
        
        for (i=0 ; i<m ; i++ ) {
            n = accounts[i].size();
            sum = 0;
            for( j=0 ; j<n ; j++ ) {
                sum += accounts[i][j];
            }
            w = max(w, sum);
        }
        
        return w;
    }
};