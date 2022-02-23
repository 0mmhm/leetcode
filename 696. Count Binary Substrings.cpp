class Solution {
public:
    int countBinarySubstrings(string s) {
        char ch = s[0];
        int i, a, b, res, len = s.length();
        a = b = res = 0;
        bool ob = false, oa = false;
        for( i=0 ; i<len ; i++ ) {
            if(ch == s[i]) {
                if(ob) {
                    ob = false;
                    res += min(a, b);
                    a = 0;
                }
                oa = true;
                a++;
            }
            else {
                if(oa) {
                    oa = false;
                    res += min(a, b);
                    b = 0;
                }
                b++;
                ob = true;
            }
        }
        res += min(a, b);
        
        return res;
    }
};