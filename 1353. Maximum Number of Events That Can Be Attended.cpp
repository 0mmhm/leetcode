class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int i, d, attented =0, len = events.size();
        priority_queue <int, vector<int>, greater<int>> pq;
        
        sort(events.begin(), events.end());
        i = 0;
        while( !pq.empty() || i<len ) {
            if(pq.empty()) {
                d = events[i][0];
            }
            
            while(i<len && events[i][0] == d) {
                pq.push(events[i][1]);
                i++;
            }
            
            d++;
            pq.pop();
            attented++;
            
            while(!pq.empty() && pq.top() < d) {
                pq.pop();
            }
        }
        
        return attented;
    }
};