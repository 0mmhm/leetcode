class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> temp;
        stack<int> st;
        int i, len = temperatures.size();
        vector<int> res(len, 0);
        
        for( i=0 ; i<len ; i++ ) {
            temp.push_back(temperatures[i]);

            while(!st.empty() && temp[st.top()] < temp[i]) {
                res[st.top()] = i - st.top();
                st.pop();
            }
            
            st.push(i);
        }
        return res;
    }
};