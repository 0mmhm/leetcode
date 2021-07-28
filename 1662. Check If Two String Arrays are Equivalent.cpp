class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int arOneLen, arTwoLen, i;
        arOneLen = word1.size();
        arTwoLen = word2.size();
        
        string a = "", b = "";
        
        for( i=0 ; i<arOneLen ; i++ ) a += word1[i];
        for( i=0 ; i<arTwoLen ; i++ ) b += word2[i];
        
        if( a == b ) return true;
        return false;
    }
};