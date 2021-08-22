class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, k = s.size() - 1;
        char temp;
        while( i<=k ) {
            temp = s[i];
            s[i] = s[k];
            s[k] = temp;
            i++;
            k--;
        }
    }
};