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