class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int i, j, m, n;
        
        m = grid.size();
        n = grid[0].size();
        
        for( i=1 ; i<n ; i++ ) grid[0][i] += grid[0][i-1];
        for( i=1 ; i<m ; i++ ) grid[i][0] += grid[i-1][0];
        
        for( i=1 ; i<m ; i++ ) {
            for( j=1 ; j<n ; j++ ){
                grid[i][j] += min( grid[i-1][j], grid[i][j-1] );
            }
        }
        
        return grid[m-1][n-1];
    }
};

/*
class Solution {
public:
    int dir[2][2] = {{0, 1}, {1, 0}}; 
    int m, n, minSum = 40000000;
    int mark[201][201];
    
    bool isValid(int x, int y){
        if(0<=x && x<m && 0<=y && y<n) return true;
        return false;
    }
    
    void findMinPathSum(int x, int y, vector<vector<int>>& grid, int sum) {
        if(x==m-1 && y == n-1) {
            minSum = min(minSum, sum);
            return;
        }
        
        int a, b;
        for(int i=0 ; i<2 ; i++ ){
            a = x + dir[i][0];
            b = y + dir[i][1];
            
            if(isValid(a, b) && !mark[a][b]) {
                mark[a][b] = sum + grid[a][b];
                findMinPathSum(a, b, grid, sum+grid[a][b]);
            }
            else if(isValid(a, b)) {
                if( sum+grid[a][b] < mark[a][b] ) {
                    mark[a][b] = sum + grid[a][b];
                    findMinPathSum(a, b, grid, sum+grid[a][b]);
                }
            }
        }
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int i, j;
        
        for( i=0 ; i<m ; i++ ){
            for( j=0 ; j<n ; j++ ) mark[i][j] = 0;
        }
        findMinPathSum(0, 0, grid, grid[0][0]);
        
        return minSum;
    }
};
*/