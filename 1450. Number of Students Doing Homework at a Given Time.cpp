class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int i, len, res = 0;
        len = endTime.size();
        
        for( i=0 ; i<len ; i++ ) {
            if( startTime[i] <= queryTime && queryTime <= endTime[i] ) res++;
        }
        
        return res;
    }
};