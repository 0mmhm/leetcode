class Solution {
public:
    int uniquePaths(int m, int n) {
        int grid[m][n];
        int i, j;
        
        for( i=1 ; i<m ; i++ ) {
            for( j=1 ; j<n ; j++ ) {
                grid[i][j] = 0;
            }
        }
        
        for( i=0 ; i<m ; i++ ) grid[i][0] = 1;
        for( j=0 ; j<n ; j++ ) grid[0][j] = 1;
        
        for( i=1 ; i<m ; i++ ) {
            for( j=1 ; j<n ; j++ ) {
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }
        
        return grid[m-1][n-1];
    }
};