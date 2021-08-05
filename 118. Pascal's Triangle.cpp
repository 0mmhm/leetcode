class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.clear();
        
        for(int i=0 ; i<numRows ; i++ ) {
            vector <int> row;
            row.clear();
            if( i == 0){
                row.push_back(1);
                res.push_back(row);
                continue;
            }
            
            int len = res[i-1].size();
            row.push_back(1);
            for(int j=0 ; j<len - 1  ; j++ ) {
                row.push_back( res[i-1][j] + res[i-1][j+1] );
            }
            row.push_back(1);
            res.push_back(row);
        }
        return res;
    }
};