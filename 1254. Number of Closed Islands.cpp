class Solution {
public:
    int row, col;
    int dir[4][2] ={ {0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    bool isClosedIsland;
    
    bool isValid(int r, int c){
        if(r>=0 && r<row && c>=0 && c<col)
            return true;
        return false;
    }
    
    bool isCorner(int i, int j){
        if(i>0 && i<row-1 && j>0 && j<col-1)
            return false;
        return true;
    }
    
    void findClosedIsland(int i, int j, vector<vector<int>>& grid) {
        grid[i][j] = -1;
        
        int k, x, y;
        for(k=0 ; k<4 ; k++) {
            x = i + dir[k][0];
            y = j + dir[k][1];
            
            if(isValid(x, y) && !isCorner(x, y) && grid[x][y] == 0) {
                findClosedIsland(x, y, grid);
            }
            else if(isValid(x, y) && isCorner(x, y) && grid[x][y] == 0)
                isClosedIsland = false;
                
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        row = grid.size(); col = grid[0].size();
        
        int i, j, closedIsland = 0;
        for( i=0 ; i<row ; i++ ) {
            for( j=0 ; j<col ; j++ ) {
                if(isValid(i, j) && !isCorner(i, j) && grid[i][j] == 0) {
                    isClosedIsland = true;
                    findClosedIsland(i, j, grid);
                    
                    if(isClosedIsland)
                        closedIsland++;
                }
            }
        }
        
        return closedIsland;
    }
};