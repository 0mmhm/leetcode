class Solution {
public:
    struct POINTS{
        int dis, x, y;
        
        POINTS(int x, int y) : x(x), y(y) {
            dis = (x*x) + (y*y);
        }
    };
    
    struct compare{
        bool operator()(POINTS const& x, POINTS const& y) {
            return x.dis > y.dis;
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<POINTS, vector<POINTS>, compare> pq;
        pq =  priority_queue<POINTS, vector<POINTS>, compare>();
        int i, len = points.size();
        
        for( i=0 ; i<len ; i++ ) {
            POINTS p = POINTS(points[i][0], points[i][1]);
            pq.push(p);
        }
        
        i = 0;
        vector<vector<int>> res;
        res.clear();
        
        while( i<k) {
            POINTS p = pq.top(); pq.pop();
            res.push_back({p.x, p.y});
            i++;
        }
        
        return res;
    }
};