class Solution {
public:
    struct Interval {
        int start, end, ind;
    };
    
    static bool compareIntervals(Interval a, Interval b) {
        if( a.start < b.start ) return true;
        else if(a.start == b.start && a.end < b.end) return true;
        
        return false;
    }
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int i, len = intervals.size();
        Interval interval[len];
        
        for( i=0 ; i<len ; i++ ) {
            interval[i].start = intervals[i][0];
            interval[i].end = intervals[i][1];
            interval[i].ind = i;
        }
        vector<int> res(len);
        sort(interval, interval+len, compareIntervals);
        
        for( i=0 ; i<len ; i++ ) {
            int s, e, ind, st, en, mid, fInd;
            s = interval[i].start;
            e = interval[i].end;
            ind = interval[i].ind;
            
            st = 0; en = len-1; fInd = -1;
            while(st<=en) {
                mid = (en+st) / 2;
                if( interval[mid].start >= e) {
                    fInd = interval[mid].ind;
                    en = mid-1;
                }
                else if(interval[mid].start >= e) en = mid - 1;
                else st = mid + 1;
                
             }
            
            res[ind] = fInd;
        }
        
        return res;
        
    }
};