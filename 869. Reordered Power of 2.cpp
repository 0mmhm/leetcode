class Solution {
public:
    void isSame(string strNum, string str, bool* res) {
        int i, len;
        len = strNum.length();
        
        unordered_map<char, int> mp, sp;
        mp.empty();
        sp.empty();
        
        for( i=0 ; i<len ; i++ ) {
            sp[strNum[i]]++;
            mp[str[i]]++;
        }
        
        *res = true;
        
        for( i=0 ; i<10 ; i++ ){
            char c = i + '0';
            if(mp[c] != sp[c]) {
                *res = false;
                return;
            }
        }
        
    }
    
    bool reorderedPowerOf2(int n) {
        int i, num = 1;
        string str, strNum = to_string(n);
        vector<string> v;
        
        while(num <= 1000000000) {
            str = to_string(num);
            v.push_back(str);
            num = num*2;
        }
        
        int len = strNum.length();
        bool res = false;
        for( i=0 ; i<v.size() ; i++ ) {
            if(len == v[i].length()) {
                isSame(strNum, v[i], &res);
            }
            
            if(res) break;
        }
        
        return res;
    }
};