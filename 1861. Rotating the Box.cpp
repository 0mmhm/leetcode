class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int i, j, k, p, n, m = box.size();
        n = box[0].size();
        vector<vector<char>> res(m, vector<char>(n, '1'));
        
        for( i=m-1 ; i>=0 ; i-- ) {
            n = box[i].size();
            p = j = n-1;
            vector <char> v(n);
            while(j >= 0) {
                if(box[i][j] == '*') {
                    p = j - 1;
                    res[i][j] = '*';
                }
                else if(box[i][j] == '#') {
                    res[i][p] = '#';
                    p--;
                }
                j--;
            }
            k--;
        }
        
        vector<vector<char>> retVec;
        vector<char> v;
        for( i=0 ; i<n ; i++ ) {
            v.clear();
            for( j=m-1 ; j>=0 ; j-- ) {
                if(res[j][i] == '1') v.push_back('.');
                else v.push_back(res[j][i]);
            }
            retVec.push_back(v);
        }
        
        return retVec;
    }
};