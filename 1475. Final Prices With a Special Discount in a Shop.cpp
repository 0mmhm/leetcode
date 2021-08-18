class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int i, len = prices.size();
        stack <int> st;
        
        for( i=0 ; i<len ; i++ ) {
            while( !st.empty() && prices[st.top()] >= prices[i] ) {
                prices[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return prices;
    }
};