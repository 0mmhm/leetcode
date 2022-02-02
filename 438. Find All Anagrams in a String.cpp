class Solution {
public:
    vector<int> res;
    int smap[26], pmap[26];
    
    vector<int> findAnagrams(string s, string p) {
        int lens, lenp, i;
        lens = s.length(); lenp = p.length();
        res.clear();
        
        for( i=0 ; i<26 ; i++ ) smap[i] = pmap[i] = 0;
        for( i=0 ; i<lenp ; i++ ){
            pmap[p[i] - 'a']++;
        }
        
        int a, b;
        a = b = 0;
        
        while(b < lens && a<lens) {
            smap[s[b]-'a']++;
            while(a<lens && smap[s[b]-'a'] > pmap[s[b]-'a']) {
                smap[s[a]-'a']--;
                a++;
            }
            
            if( b-a+1 == lenp ) res.push_back(a);
            b++;
        }
        
        return res;
    }
};

/*                          // sliding Window
class Solution {
public: 
    bool check(int pmap[], int smap[]) {
        int i;
        for( i=0 ; i<26 ; i++ ) {
            if(pmap[i] != smap[i]) return false;
        }
        
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        int i, j, lens, lenp;
        lens = s.length(); lenp = p.length();
        
        int pmap[26], smap[26];
        for( i=0 ; i<26 ; i++ ) pmap[i] = smap[i] = 0;
        
        for(i=0 ; i<lenp ; i++) pmap[p[i]-'a']++;
        
        vector<int> res;
        i = j = 0;
        while(j<lens) {
            smap[s[j]-'a']++;
            
            if( j - i + 1 == lenp ) {
                bool ret = check(pmap, smap);
                if(ret) res.push_back(i);
                smap[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        
        return res;
    }
};

*/