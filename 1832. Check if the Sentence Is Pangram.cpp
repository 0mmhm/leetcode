class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> v(26, 0);
        int len = sentence.length();
        int val, count = 0;
        
        for(int i=0 ; i<len ; i++ ){
            val = sentence[i] - 'a';
            if(v[val] == 0) {
                v[val]++;
                count++;
            }
        }
        
        if(count == 26) return true;
        return false;
    }
};