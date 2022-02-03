class Solution {
public:
    #define size 52
    
    int findInd(char ch) {
        if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 26; 
        return ch - 'a';
    }
    
    string minWindow(string s, string t) {
        
        int i, j, k, lens, lent, smap[size], tmap[size];
        bool map[size];
        int trueCount = 0, minWindow = 100009, x = -1, y = -1, ind, xind;
        
        lens = s.length(); lent = t.length();
        for( i=0 ; i<size ; i++ ) smap[i] = tmap[i] = map[i] = 0;
        for( i=0 ; i<lent ; i++ ) {
            ind = findInd(t[i]);
            tmap[ind]++;
        }
        for( i=0 ; i<size ; i++ ) {
            if(smap[i]==tmap[i]) {
                map[i] = true;
                trueCount++;
            }
        }
        for( i=0, j=0 ; j<lens ; j++ ) {
            ind = findInd(s[j]);
            smap[ind]++;
            
            if(smap[ind] >= tmap[ind] && !map[ind]) {
                map[ind] = true;
                trueCount++;
            }
            
            xind = findInd(s[i]);
            while( i<lens && smap[xind] - 1 >= tmap[xind] ){ 
                smap[xind]--;
                i++;
                xind = findInd(s[i]);
            }
            if(trueCount == size) {
                if( minWindow > j-i+1) {
                    minWindow =  j-i+1;
                    x = i; y = j;
                }

                xind = findInd(s[i]);
                smap[xind]--;
                if(smap[xind] < tmap[xind] && map[xind]) {
                    map[xind] = false;
                    trueCount--;
                }
                i++;
            }
        }
        
        string res = "";
        if(x == -1) return "";
        for( i=x ; i<=y ; i++ ) res += s[i];
        return res;
    }
};