class Solution {
public:
    string generateTheString(int n) {
        int a, c;
        a = c = 0;
        a = n;
        if( n % 2 == 0) {
            a = n - 1;
            c = 1;
        }
        
        int i;
        string res = "";
        for( i=0 ; i<a ; i++ ) res += 'a';
        if(c > 0) res += 'c';
        return res;
    }
};