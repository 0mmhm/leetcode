class Solution {
public:
    bool check(int amap[], int bmap[]) {
        for(int i=0 ; i<26 ; i++ ) {
            if(amap[i] != bmap[i]) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int i, j, lena, lenb;
        string a = s1, b = s2;
        lena = a.length(); lenb = b.length();
        
        int amap[26], bmap[26];
        for( i=0 ; i<26 ; i++ ) amap[i] = bmap[i] = 0;
        
        for( i=0 ; i<lena ; i++ ) amap[a[i]-'a']++;
        
        bool res;
        for( i=0, j=0 ; j<lenb ; j++ ) {
            bmap[b[j]-'a']++;
            
            if(j-i+1 == lena) {
                res = check(amap, bmap);
                if(res) return res;
                bmap[b[i++] - 'a']--;
            }
        }
        
        return false;
    }
};