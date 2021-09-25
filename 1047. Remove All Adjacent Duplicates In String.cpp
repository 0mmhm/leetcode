class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int len = s.length();
        
        int i = len-1;
        while( i>=0 ) {
            if(!st.empty() && st.top() == s[i]) {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
            
            i--;
        }
        
        s = "";
        while(!st.empty()) {
            s += st.top(); st.pop();
        }
        
        return s;
    }
};