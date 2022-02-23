class Solution {
public:
    int grid[3][3];
    
    int dir[4][2] = {{1, 1}, {0, 1}, {1, 0}, {1, -1}};
    
    string tictactoe(vector<vector<int>>& moves) {
        int i, j, k = 3;
        for( i=0 ; i<3 ; i++ )
            for( j=0 ; j<3 ; j++ ) 
                grid[i][j] = k++;
        
        int val, len = moves.size();
        for( i=1 ; i<=len ; i++ ) {
            if( i % 2) val = 0;
            else val = 1;
            
            grid[moves[i-1][0]][moves[i-1][1]] = val;
        }
        
        bool win = false;
        if( grid[0][0] == grid[0][1] &&
            grid[0][1] == grid[0][2] ||
            grid[0][0] == grid[1][0] &&
            grid[1][0] == grid[2][0] ||
            grid[0][2] == grid[1][2] &&
            grid[1][2] == grid[2][2] ||
            grid[2][0] == grid[2][1] &&
           grid[2][1] == grid[2][2] ||
           grid[0][1] == grid[1][1] &&
           grid[1][1] == grid[2][1] ||
           grid[1][0] == grid[1][1] &&
           grid[1][1] == grid[1][2] ||
           grid[0][0] == grid[1][1] &&
           grid[1][1] == grid[2][2] ||
           grid[2][0] == grid[1][1] &&
           grid[1][1] == grid[0][2] ) {
            win = true;
        }
        
        
        if(len < 9 && !win) return "Pending";
        else if(!win) return "Draw";
        
        int zero = 0, one = 0;
        for( i=0 ; i<3 ; i++ ) {
            for( j=0 ; j<3 ; j++ ) {
                if(grid[i][j] == 0) zero++;
                else if(grid[i][j] == 1) one++;
            }
        }
        
        if(zero > one) return "A";
        return "B";
           
        
    }
};