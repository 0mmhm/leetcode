class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row, col;
        row = matrix.size();
        col = matrix[0].size();
        
        int left, right, mid;
        left = 0; right = row-1;
        bool isFound = false;
        if(row == 1 && col == 1){
            if(matrix[0][0] == target) return true;
            return false;
        }
        
        if(row > 1){
            while(left <= right){
                mid = (left + right) / 2;

                if(matrix[mid][0] == target){
                    isFound = true;
                    break;
                }
                else if( matrix[mid][0] <= target && target<= matrix[mid][col-1]  ) {
                    right = mid;
                    break;
                }
                else if(matrix[mid][col-1] < target) left = mid + 1;
                else right = mid - 1;
            }
        }
        
        if(isFound || col == 1 || right < 0 || left >= row) return isFound;
        cout << right << endl;
        int searchInd = right;
        left = 0; right = col - 1;
        
        while(left <= right){
            mid = (left + right) / 2;

            if(matrix[searchInd][mid] == target){
                isFound = true;
                break;
            }
            else if(matrix[searchInd][mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        
        return isFound;
    }
};