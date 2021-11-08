class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map <int, int> st, en;
        int i, j, len = intervals.size();
        
        int ar[10009];
        for( i=0 ; i<10009 ; i++ ) ar[i] = -1;
        for( i=0 ; i<len ; i++ ) {
            ar[intervals[i][0]] = max(ar[intervals[i][0]], intervals[i][1]);
        }
        
        vector <vector<int>> res;
        
        int s, e;
        s = e = -1;
        for( i=0 ; i<10009 ; i++ ) {
             if(i > e && s != -1) {
                res.push_back({s, e});
                s = e = -1;
            }
            
            if(ar[i] > -1 && s == -1) {
                s = i;
                e = ar[i];
            }
            else if(ar[i]) {
                e = max(e, ar[i]);
            }
        }
        
        return res;
    }
};