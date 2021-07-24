class Solution {
public:
    
    int checkSubtractionRule(char left, char right){
        int ans = 0;
        if(left == 'I'){
            if(right == 'V') ans = 4;
            else if(right == 'X') ans = 9;
        }
        else if(left == 'X'){
            if(right == 'L') ans = 40;
            else if(right == 'C') ans = 90;
        }
        else if(left == 'C'){
            if(right == 'D') ans = 400;
            else if(right == 'M') ans = 900;
        }
        return ans;
    }
    
    int romanToInt(string s) {
        map <char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int len = s.length();
        int ret, res = 0;
        for(int i=0 ; i<len ; i++ ){
            if(i+1 < len && s[i] == 'I' || s[i] == 'X' || s[i] == 'C'){
                ret = 0;
                ret = checkSubtractionRule(s[i], s[i+1]);
                if(ret == 0) res += mp[ s[i] ];
                else{
                    res += ret;
                    i++;
                }
            }
            else res += mp[ s[i] ];
        }
        return res;
    }
};