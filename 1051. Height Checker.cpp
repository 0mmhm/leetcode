class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int i, res = 0, len = heights.size();
        vector<int> v;
        
        for( i=0 ; i<len ; i++ ) v.push_back(heights[i]);
        sort(v.begin(), v.end());
        for( i=0 ; i<len ; i++ ) if(v[i] != heights[i]) res++;
        
        return res;
    }
};