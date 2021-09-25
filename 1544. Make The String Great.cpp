class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        
        int i, len = s.length();
        
        char temp;
        i=len-1;
        while(i>=0) {
            if(!st.empty()) {
                if( st.top() < 97 && s[i] >= 97 ) {
                    temp = (s[i] - 'a') + 'A';
                    if(temp == st.top()) st.pop();
                    else st.push(s[i]);
                }
                else if(st.top() >= 97 && s[i] < 97) {
                    temp = (st.top() - 'a') + 'A';
                    if(temp == s[i]) st.pop();
                    else st.push(s[i]);
                }
                else{
                    st.push(s[i]);
                }
            }
            else {
                st.push(s[i]);
            }
            i--;
        }
        
        string res;
        while(!st.empty()) {
            res += st.top(); st.pop();
        }
        
        return res;
    }
};