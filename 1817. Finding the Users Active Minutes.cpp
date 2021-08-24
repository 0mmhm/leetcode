class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector <int> v(k, 0), uniqUsrVec;
        map <int, vector<int>>  usrActiTime;
        map <int, int> uniqUsr, uniqTime;
        
        int user, time, i, j, len = logs.size();
        
        for( i=0 ; i<len ; i++ ) {
            user = logs[i][0];
            time = logs[i][1];
            usrActiTime[user].push_back(time);
            
            if(uniqUsr[user] == 0) {
                uniqUsr[user] = 1;
                uniqUsrVec.push_back(user);
            }
        }
        
        int timeVecSize, uniqTimeCount, userLen = uniqUsrVec.size();
        for( i=0 ; i<userLen ; i++ ) {
            user = uniqUsrVec[i];
            uniqTime.clear();
            timeVecSize = usrActiTime[user].size();
            
            uniqTimeCount = 0;
            for( j=0 ; j<timeVecSize ; j++ ) {
                time = usrActiTime[user][j];
                if( uniqTime[time] == 0 ) {
                    uniqTime[time] = 1;
                    uniqTimeCount++;
                }
            }
            v[uniqTimeCount - 1]++;
        }
        
        return v;
    }
};