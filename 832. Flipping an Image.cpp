class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int i, j, k, temp, n = image.size();
        
        for( i=0 ; i<n ; i++ ) {
            j = 0; k = n-1;
            while(j<=k) {
                temp = image[i][j] ^ 1;
                image[i][j] = image[i][k] ^ 1;
                image[i][k] = temp;
                
                j++;
                k--;
            }
        }
        return image;
    }
};
