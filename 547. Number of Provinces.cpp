class Solution {
public:
    
    void markProvinceAsCounted(int x, int y, vector<vector<int>>& isConnected, int n) {
        isConnected[x][y] = -1;
        isConnected[y][x] = -1;
        
        int i;
        for(i=0 ; i<n ; i++) {
            if(isConnected[x][i] == 1) markProvinceAsCounted(x, i, isConnected, n);
        }
        
        for(i=0 ; i<n ; i++) {
            if(isConnected[y][i] == 1) markProvinceAsCounted(y, i, isConnected, n);
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int province = 0;
        int i, j, n = isConnected.size();
        
        
        for(i=0 ; i<n ; i++) {
            for(j=0 ; j<n ; j++) {
                if(isConnected[i][j] == 1){
                    province++;
                    markProvinceAsCounted(i, j, isConnected, n);   
                }
            }
        }
        
        return province;
    }
};