class Solution {
public:
    vector<vector<char>> letters{10};
    vector<int> num;
    vector<string> res;
    int size;
    
    void formCombination(int ind, string str) {
        if(ind == size) {
            res.push_back(str);
            return;
        }
        
        int i, indNum = num[ind];
        int indNumArrLength = letters[indNum].size();
        
        for( i=0 ; i<indNumArrLength ; i++ ) {
            formCombination(ind + 1, str + letters[indNum][i]);
        }
    }
    
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        int i, j, k;
        char ch = 'a';
        
        for( i=2 ; i<10 ; i++ ) {
            j = 0; k = 3;
            if( i==7 || i==9 ) k = 4;
            
            while(j<k) {
                letters[i].push_back(ch);
                ch++;
                j++;
            }
        }
        
        int len = digits.length();
        size = len;
        for( i=0 ; i<len ; i++ ) num.push_back(digits[i] - '0');
        
        formCombination(0, "");
        
        return res;
    }
};