class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int i, j, ind, left, right, mid, tg = -1;
        int cl, len = grid.size();
        int res = 0;
        for( i=0 ; i<len ; i++ ){
            cl = grid[i].size();
            left = 0; right = cl-1;
            ind = -1;
            while(left <= right){
                mid = (left + right) / 2;
                if(grid[i][mid] < 0){
                    right = mid - 1;
                    ind = mid;
                }
                else if(grid[i][mid] > tg) left = mid + 1;
                else right = mid - 1; 
            }
            if(ind >= 0) res += (cl - ind); 
        }
        return res;
    }
};