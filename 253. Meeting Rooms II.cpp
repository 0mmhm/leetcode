class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int i, topVal, currSt, currEn, res =0, len = intervals.size();
        res = 1;
        pq.push(intervals[i][1]);
        for( i=1 ; i<len ; i++ ) {
            currSt = intervals[i][0];
            currEn = intervals[i][1];

            topVal = pq.top();
            if(topVal > currSt) {
                res++;
            }
            else {
                pq.pop();
            }
            pq.push(currEn);
        }
        
        return res;    
    }
};

/*
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int i, j, res =0, len = intervals.size();
        
        vector<int> room;
        int s, st, en;
        room.push_back(intervals[0][1]);
        s = 1;
        bool placed;
        
        for( i=1 ; i<len ; i++ ) {
            st = intervals[i][0];
            en = intervals[i][1];
            placed = false;
            for( j=0 ; j<s ; j++ ) {
                if(room[j] <= st) {
                    room[j] = en;
                    placed = true;
                    break;
                }
            }
            if(!placed) {
                s++;
                room.push_back(en);
            }
        }
        
        return room.size();    
    }
};
*/