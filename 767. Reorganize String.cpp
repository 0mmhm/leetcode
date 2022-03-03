class Solution {
public:
    string reorganizeString(string s) {
        int freq[26], i, j, len = s.length();
        
        for( i=0 ; i<26 ; i++ ) freq[i] = 0;
        for( i=0 ; i<len ; i++ ) freq[s[i] - 'a']++;
        
        string str = "";
        char prev = ' ';
        for( i=0 ; i<len ; i++ ) {
            int curMax = 0, ind;
            for( j=0 ; j<26 ; j++ ) {
                if(freq[j] > curMax && j+'a' != prev) {
                    curMax = freq[j];
                    ind = j;
                }
            }
            
            if(curMax == 0) return "";
            str += (ind + 'a');
            freq[ind]--;
            prev = ind + 'a';
        }
        return str;
    }
};