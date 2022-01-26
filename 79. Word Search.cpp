class Solution {
public:
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n, wordLen;
    bool mark[7][7];
    bool res;
    
    bool isValid(int a, int b) {
        if(a>=0 && a<m && b>=0 && b<n) return true;
        return false;
    }
    
    void search(int x, int y, vector<vector<char>>& v, int ind, string w) {
        if(ind>wordLen){
            res = true;
            return;
        }
        
        int a, b, i;
        for( i=0 ; i<4 ; i++ ) {
            a = x + dir[i][0];
            b = y + dir[i][1];
            
            if(isValid(a, b) && v[a][b] == w[ind] && !mark[a][b]) {
                mark[a][b] = true;
                search(a, b, v, ind+1, w);
                mark[a][b] = false;
            }
        }
        
        return;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        wordLen = word.size() - 1;
        
        char s = word[0];
        int i, j;
        for( i=0 ; i<7 ; i++ ) {
            for( j=0 ; j<7 ; j++ ) {
                mark[i][j] = false;
            }
        }
        
        for( i=0 ; i<m ; i++ ) {
            for( j=0 ; j<n ; j++ ) {
                if( board[i][j] == s ) {
                    res = false;
                    mark[i][j] = true;
                    search(i, j, board, 1, word);
                    mark[i][j] = false;
                    if(res) return true;
                }
            }
        }
        
        return false;
    }
};