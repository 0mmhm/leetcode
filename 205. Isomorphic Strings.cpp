class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map <char, char> mp, xp;
        
        int len = s.length();
        for(int i=0 ; i<len ; i++ ){
            if(mp[ s[i] ] == 0 && xp[ t[i] ] == 0 ){
                mp[ s[i] ] = t[i];
                xp[ t[i] ] = s[i];
            }
            else if(mp[ s[i] ] != t[i]){
                return false;
            }
        }
        
        return true;
        
    }
};