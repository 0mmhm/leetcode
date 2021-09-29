class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int i, lena, lenb;
        lena = nums1.size();
        lenb = nums2.size();
        
        int size = 10004;
        vector<int> nextGreat(size, -1);
        stack<int> st;
        
        for( i=0 ; i<lenb ; i++ ) {
            while(!st.empty() && nums2[st.top()] < nums2[i] ) {
                nextGreat[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            
            st.push(i);
        }
        
        vector<int> res(lena);
        for( i=0 ; i<lena ; i++ ) {
            res[i] = nextGreat[nums1[i]];
        }
        
        return res;
    }
};