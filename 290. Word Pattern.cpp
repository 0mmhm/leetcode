class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string word;
        map <char, string> mp;
        map <string, char> xp;
        int len = s.length();
        int patLen = pattern.length();
        int i, j = -1;
        
        for( i=0 ; i<len ; i++ ){
            if(j == patLen) return false;
            
            if(s[i] == ' '){
                j++;
                if( mp[ pattern[j] ] == "" && xp[word] == 0){
                    mp[ pattern[j] ] = word;
                    xp[word] = pattern[j];
                }
                else if( mp[ pattern[j] ] != word || xp[word] != pattern[j]) return false;
                word = "";
            }
            else word += s[i];
        }
        
        if(word.length() > 0){
            if(j >= patLen) return false;
            j++;
            if( mp[ pattern[j] ] == "" && xp[word] == 0){
                mp[ pattern[j] ] = word;
                xp[word] = pattern[j];
            }
            else if( mp[ pattern[j] ] != word || xp[word] != pattern[j]) return false;
        }
        
        if( j != patLen-1 ) return false;
        return true;
    }
};