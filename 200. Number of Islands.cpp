class Solution {
public:
    bool mark[300][300];
    int dir[4][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };
    int r, c;
    
    bool isValid(int row, int col) {
        if(col>=0 && col<c && row>=0 && row<r) return true;
        return false;
    }
    
    void markIsland(int x, int y, vector<vector<char>>& grid) {
        int i, a, b;
        
        for( i=0 ; i<4 ; i++ ) {
            a = x + dir[i][0];
            b = y + dir[i][1];
            
            if(isValid(a, b) && grid[a][b] == '1' && !mark[a][b]) {
                mark[a][b] = true;
                markIsland(a, b, grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int i, j;
        
        r = grid.size(); c = grid[0].size();
        
        for( i=0 ; i<r ; i++ ) {
            for( j=0 ; j<c ; j++ ) {
                mark[i][j] = false;
            }
        }
        
        int island = 0;
        for( i=0 ; i<r ; i++ ) {
            for( j=0 ; j<c ; j++ ) {
                if(grid[i][j] == '1' && !mark[i][j]) {
                    island++;
                    mark[i][j] = true;
                    markIsland(i, j, grid);
                }
            }
        }
        
        return island;
    }
};