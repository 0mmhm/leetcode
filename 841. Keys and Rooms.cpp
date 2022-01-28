class Solution {
public:
    map<int, int> mp;
    queue<int> q;
    int visited, roomCount;
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        roomCount = rooms.size();
        bool mark[roomCount];
        for(int k=0 ; k<roomCount ; k++ ) mark[k] = false;
        visited = 1;
        mark[0] = true;
        q.push(0);
        
        int i, j, r, keys, key;
        keys = rooms[0].size();
        for( j = 0; j<keys ; j++ ) q.push(rooms[0][j]);

        while(!q.empty()) {
            r = q.front(); q.pop();
            
            int len = rooms[r].size();
            for( i=0 ; i<len ; i++ ) {
                if(!mark[rooms[r][i]]){
                    q.push(rooms[r][i]);
                    mark[rooms[r][i]] = true;
                    visited++;
                }
            }
            
            if(visited == roomCount) return true;
        }
        
        return false;
    }
};