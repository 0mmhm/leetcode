class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map <char, int> mp;
        int i, len = s.length();
        
        for( i=0 ; i<len ; i++ ) {
            mp[s[i]]++;
        }
        
        int ind = -1;
        for( i=0 ; i<len ; i++ ) {
            if( mp[s[i]] == 1) {
                ind = i;
                break;
            }
        }
        
        return ind;
    }
};