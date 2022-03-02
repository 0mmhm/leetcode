class Solution {
public:
    int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    int m, n, fresh, rotten;
    vector<vector<int>> markv;
    
    bool isValid(int r, int c) {
        if(r>=0 && r<m && c>=0 && c<n) return true;
        return false;
    }
    
    void makeCopy(vector<vector<int>>& grid, vector<vector<int>>& v, int tag) {
        int i, j;
        for( i=0 ; i<m ; i++ ) {
            if(!tag) markv.push_back({});
            for( j=0 ; j<n ; j++ ) {
                if(tag) v[i][j] = grid[i][j];
                else {
                    if(grid[i][j] == 1) fresh++;
                    else if(grid[i][j] == 2) rotten++;
                    markv[i].push_back(grid[i][j]);
                }
            }
        }
    }
    
    queue<int> q;
    
    int rottenTime(vector<vector<int>>& v) {
        int time = 0, r, c, x, y, i, j;
        
        while(!q.empty()) {
            r = q.front(); q.pop();
            c = q.front(); q.pop();
            markv[r][c] = 3;
            
            for( i=0 ; i<4 ; i++ ) {
                x = r + dir[i][0];
                y = c + dir[i][1];

                if(isValid(x, y) && v[x][y] == -1) {
                    v[x][y] = v[r][c] + 1;
                    q.push(x);
                    q.push(y);
                    
                    if(markv[x][y] == 1) {
                        markv[x][y] = 2;
                        fresh--;
                    }
                }
                else if(isValid(x, y) && v[x][y] && v[x][y] > v[r][c] + 1) {
                    v[x][y] = v[r][c] + 1;
                    q.push(x);
                    q.push(y);
                       
                }
            }
        }
        
        for( i=0 ; i<m ; i++ ) {
            for( j=0 ; j<n ; j++ ) {
                time = max(time, v[i][j]);
            }
        }
        return time;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int i, j;
        
        vector<vector<int>> v(m, vector<int>(n));
        fresh = rotten = 0;
        makeCopy(grid, markv, 0);
        if(!fresh) return 0;
        if(!rotten) return -1;
        
        int minTime = 0;
        for( i=0 ; i<m ; i++ ) {
            for( j=0 ; j<n ; j++ ) {
                if(grid[i][j] == 2) {
                    grid[i][j] = 0;
                    q.push(i);
                    q.push(j);
                }
                
                int *val = &grid[i][j];
                if(*val == 1) *val = -1;
                else if(*val == 2) *val = -2;
            }
        }
        
        minTime = rottenTime(grid);
        
        if(fresh > 0) return -1;
        return minTime;
    }
};