class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m, n, i, k;
        m = obstacleGrid.size(); n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1) return 0;

        int fil = 1;
        for( i=0 ; i<n ; i++ ){
            if( obstacleGrid[0][i] == 1 ) fil = 0;
            obstacleGrid[0][i] = fil;
        }

        fil = 1;
        for( k=1 ; k<m ; k++ ) {
            if( obstacleGrid[k][0] == 1) fil = 0;
            obstacleGrid[k][0] = fil;
        }
        
        for( i=1 ; i<m ; i++ ) {
            for( k=1 ; k<n ; k++ ) {
                if( obstacleGrid[i][k] == 1) obstacleGrid[i][k] = 0;
                else obstacleGrid[i][k] = obstacleGrid[i-1][k] + obstacleGrid[i][k-1];
            }
        }
        
        return obstacleGrid[m-1][n-1];
    }
};