class Solution {
public:
    struct Points {
        int start, end;
    };
    
    static bool comparePoints(Points a, Points b) {
        if(a.start < b.start) return true;
        else if((a.start == b.start) && (a.end < b.end)) return true;
        
        return false;
    }  
    
    int findMinArrowShots(vector<vector<int>>& points) {
        int i, s, e, len = points.size();
        Points v[len];
        
        Points p;
        for( i=0 ; i<len ; i++ ) {
            p.start = points[i][0];
            p.end = points[i][1];
            v[i] = p;
        }
        sort(v, v+len, comparePoints);
        
        for( i=0 ; i<len ; i++ ) cout << v[i].start << " " << v[i].end << endl;
        
        int res = 1;
        s = v[0].start; e = v[0].end;
        for( i=1 ; i<len ; i++ ) {
            if(s <= v[i].start && v[i].start <= e){
                e = min(e, v[i].end);
            }
            else{
                res++;
                s = v[i].start;
                e = v[i].end;
            }
        }
        
        return res;
    }
};