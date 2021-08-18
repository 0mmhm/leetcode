class Solution {
public:
    int maxDepth(string s) {
        stack <char> st;
        
        char topEle;
        int i, depth = 0, maxDepth = 0, len = s.length();
        
        for( i=0 ; i<len ; i++ ) {
            if(s[i] == '('){
                st.push(s[i]);
                depth++;
                maxDepth = max(depth, maxDepth);
            }
            else if(s[i] == ')') {
                st.pop();
                depth--;
            } 
        }
        return maxDepth;
    }
};