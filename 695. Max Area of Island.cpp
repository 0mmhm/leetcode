class Solution {
public:
    int dir[4][2] = {{1,0}, {0,1}, {-1, 0}, {0,-1}};
    int m, n, area;
    
    bool isValid(int a, int b) {
        if(a>=0 && a<m && b>=0 && b<n) return true;
        return false;
    }
    
    void color(int x, int y, vector<vector<int>>& v) {
        v[x][y] = 0;
        area++;
        
        int a, b, i;
        for( i=0 ; i<4 ; i++ ) {
            a = x + dir[i][0];
            b = y + dir[i][1];
            
            if(isValid(a, b) && v[a][b] == 1) {
                color(a, b, v);
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int i, j, ans = 0;
        for( i=0 ; i<m ; i++ ) {
            for( j=0 ; j<n ; j++ ) {
                if(grid[i][j] == 1) {
                    area = 0;
                    color(i, j, grid);
                    ans = max(ans, area);
                }
            }
        }
        
        return ans;
    }
};