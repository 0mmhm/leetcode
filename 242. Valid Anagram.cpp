class Solution {
public:
    bool isAnagram(string s, string t) {
        int i, arr[26];
        int lens = s.length(), lent = t.length();
        
        if(lens != lent) return false;
        
        for( i=0 ; i<26 ; i++ ) arr[i] = 0;
        for( i=0 ; i<lens ; i++ ) arr[s[i] - 'a']++;
        for( i=0 ; i<lent ; i++ ) arr[t[i] - 'a']--;
        
        for( i=0 ; i<26 ; i++ ) if(arr[i] != 0) return false;
        
        return true;
    }
};