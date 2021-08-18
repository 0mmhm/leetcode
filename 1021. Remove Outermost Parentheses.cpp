class Solution {
public:
    string removeOuterParentheses(string s) {
        int i, len = s.length();
        string str = "";
        stack <char> st;
        
        int depth = 0;
        for( i=0 ; i<len ; i++ ) {
            if(s[i] == '(' ) {
                if(depth == 0) {
                    st.push(s[i]);
                }
                else{
                    str += s[i];
                }
                depth++;
            }
            else {
                depth--;
                if(depth != 0) {
                    str += s[i];
                }
            }
        }
        return str;
    }
};