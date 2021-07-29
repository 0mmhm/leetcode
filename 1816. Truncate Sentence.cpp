class Solution {
public:
    string truncateSentence(string s, int k) {
        int i, space = 0, len = s.length();
        
        string res = "";
        for( i=0 ; i<len ; i++ ){
            if(space == k) break;
            else if(s[i] == ' '){
                space++;
                
                if(space < k) res += s[i];
            }
            else
                res += s[i];
        }
        
        return res;
    }
};