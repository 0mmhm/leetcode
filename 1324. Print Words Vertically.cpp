class Solution {
public:
    vector <string> res;
    
    int maximum(int a, int b){
        if(a > b) return a;
        return b;
    }
    
    string removeSpace(string str){
        int i, len = str.length();
        string res = "";
        int a, b;
        a = 0; b = len;
        for( i=len-1 ; i>=0 ; i--) {
            if(str[i] != ' ') {
                b = i; break;
            }
        }
        
        for( i=a ; i<=b ; i++ ){
            res += str[i];
        }
        return res;
    }
    
    vector<string> printVertically(string s) {
        vector<vector<char>> data;
        vector<char> v;
        int i, j, len = s.length();
        
        for( i=0 ; i<len ; i++ ){
            if(s[i] == ' '){
                if(v.size() > 0) data.push_back(v);
                v.clear();
            }
            else {
                v.push_back(s[i]);
            }
        }
        if(v.size() > 0) data.push_back(v);
        
        
        int lena, lenb, maxLenb = -1;
        lena = data.size();
        string str;
        for( i=0 ; i<lena ; i++ ){
            maxLenb = maximum( maxLenb, data[i].size() );
        }
        
        
        for( j=0 ; j<maxLenb ; j++ ){
            str = "";
            for( i=0 ; i<lena ; i++ ) {
                lenb = data[i].size();
                if(j<lenb) {
                    str += data[i][j];
                }
                else str += " ";
            }
            res.push_back(removeSpace(str));
        }
        
        
        
        return res;
    }
};