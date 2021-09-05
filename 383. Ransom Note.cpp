class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int i, lenb, lena = magazine.length();   
        map <char, int> mp;
        for( i=0 ; i<lena ; i++ ) mp[magazine[i]]++;
        
        lenb = ransomNote.length();
        for( i=0 ; i<lenb ; i++ ) {
            if( mp[ransomNote[i]] == 0 ) return false;
            mp[ransomNote[i]]--;
        }
        
        return true;
    }
};