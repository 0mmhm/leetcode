class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int len = indices.size();
        
        int i, ar[len+1];
        string res = "";
        for( i=0 ; i<len ; i++ ) {
            ar[ indices[i] ] = s[i];
        }
        
        for( i=0 ; i<len ; i++ ){
            res += ar[i];
        }
        return res;
    }
};