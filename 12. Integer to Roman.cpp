class Solution {
public:
    unordered_map<int, string> mp;
    vector<int> v;
    
    void doMap() {
        mp[1000] = "M";
        mp[900] = "CM";
        mp[500] = "D";
        mp[400] = "CD";
        mp[100] = "C";
        mp[90] = "XC";
        mp[50] = "L";
        mp[40] = "XL";
        mp[10] = "X";
        mp[9] = "IX";
        mp[5] = "V";
        mp[4] = "IV";
        mp[1] = "I";
    }
    
    string res = "";
    int number;
    
    void addValue(int times, int num) {
        for(int i=1 ; i<=times ; i++ ) res += mp[num];
    }
    
    void check(int checkVal) {
        int x = 0;
        if( number >= checkVal ) {
            x = number / checkVal;
            number -= (x * checkVal);
            addValue(x, checkVal);
        }
    }
    
    string intToRoman(int num) {
        doMap();
        number = num;
        
        int checkVal;
        for(auto it=mp.begin() ; it!=mp.end() ; it++ ) {
            checkVal = it->first;
            v.push_back(checkVal);
        }
        sort(v.begin(), v.end());
        for(int i=v.size()-1 ; i>=0 ; i-- ) check(v[i]);
        
        return res;
    }
};