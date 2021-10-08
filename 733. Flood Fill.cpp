class Solution {
public:
    int dir[4][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };
    int r, c;
    bool mark[51][51];
    
    bool isValid(int x, int y) {
        if(x>=0 && x<r && y>=0 && y<c) return true;
        
        return false;
    }
    
    void doFloodFill(vector<vector<int>>& image, int x, int y, int newColor, int startingColor) {
        image[x][y] = newColor;
        
        int a, b;
        for(int i=0 ; i<4 ; i++) {
            a = x + dir[i][0];
            b = y + dir[i][1];
            
            if(isValid(a, b) && image[a][b] == startingColor && mark[a][b] == false) {
                mark[a][b] = true;
                doFloodFill(image, a, b, newColor, startingColor);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        r = image.size();
        c = image[0].size();
        
        mark[sr][sc] = true;
        doFloodFill(image, sr, sc, newColor, image[sr][sc]);
        
        return image;
    }
};