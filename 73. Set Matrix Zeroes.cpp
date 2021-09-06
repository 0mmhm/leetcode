class Solution {
public:
    int row, col;
    
    void changeValueToZero(int r, int c, vector<vector<int>>& matrix) {
        int i;
        for( i=0 ; i<col ; i++ ) matrix[r][i] = 0;
        for( i=0 ; i<row ; i++ ) matrix[i][c] = 0;
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        int i, j;
        row = matrix.size();
        vector <int> rowL, colL;
        for( i=0 ; i<row ; i++ ) {
            col = matrix[i].size();
            for( j=0 ; j<col ; j++ ) {
                if(matrix[i][j] == 0) {
                    rowL.push_back(i);
                    colL.push_back(j);
                }
            }
        }
        
        int len = rowL.size();
        for( i=0 ; i<len ; i++ ) {
            changeValueToZero(rowL[i], colL[i], matrix);
        }
        
        return;
    }
};