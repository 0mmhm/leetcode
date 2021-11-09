#define MAXNODE 101

class Solution {
public:
    
    int net[MAXNODE][MAXNODE], time[MAXNODE];
    
    int N, isAllVisited, timeTakenToVisit;
    
    void sendSignal(int n) {
        int i;
        for( i=1 ; i<=N ; i++ ) {
            if(net[n][i] != -1) {
                if( time[i] == -1 ) {
                    time[i] = time[n] + net[n][i];
                    sendSignal(i);
                }
                else if(time[i] > time[n] + net[n][i]) {
                    time[i] = time[n] + net[n][i];
                    sendSignal(i);
                }
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int i, j;
        for( i=0 ; i<=n ; i++ ) {
            time[i] = -1;
            for( j=0 ; j<=n ; j++ ) {
                net[i][j] = -1;
            }
        }
        
        int len = times.size();
        for( i=0 ; i<len ; i++ ) {
            net[times[i][0]][times[i][1]] = times[i][2];
        }
        
        N = n;
        
        isAllVisited = true;
        timeTakenToVisit = 0;
        time[k] = 0;
        
        sendSignal(k);
        
        for( i=1 ; i<=n ; i++ ) {
            if(time[i] == -1) {
                isAllVisited = false;
                break;
            }
        }
        
        
        if(isAllVisited) {
            for( i=1 ; i<=n ; i++ ) {
                timeTakenToVisit = max(timeTakenToVisit, time[i]);
            }
            return timeTakenToVisit;
        }
        
        return -1;
    }
};