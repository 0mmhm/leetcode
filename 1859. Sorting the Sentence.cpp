class Solution {
public:
    string sortSentence(string s) {
        vector <string> str;
        int pos[10];
        
        int i, j = -1, ind, len = s.length();
        string tempStr = "";
        
        for( i=0 ; i<len ; i++ ) {
            if( s[i] == ' ' ){
                j++;
                str.push_back(tempStr);
                pos[ind] = j;
                tempStr = "";
                
            }
            else if( s[i] >= '0' && s[i] <= '9') {
                ind = s[i] - '0';
            }
            else {
                tempStr += s[i];
            }
        }
        
        if(tempStr != "") {
            j++;
            str.push_back(tempStr);
            pos[ind] = j;
        }
        
        string res = "";
        int strVecLen = str.size();
        for( i=0 ; i<strVecLen ; i++ ){
            if( i!= 0 ) res += ' ';
            res += str[ pos[i+1] ];
        }
        return res;
    }
};