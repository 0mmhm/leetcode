class Solution {
public:
    int strStr(string haystack, string needle) {
        string a, b;
        int lenH = haystack.length();
        int lenN = needle.length();
        
        if(lenN == 0) return 0;
        if(lenH == 0) return -1;
        
        int i, j, k;
        for(i=0 ; i<lenH ; i++) {
            if(haystack[i] == needle[0] && i+lenN <= lenH) {
                for(j=0, k=i ; j<lenN ; j++, k++) {
                    if(needle[j] != haystack[k]) break;
                }
                if(j == lenN) return i;
            }
        }
        return -1;
    }
};