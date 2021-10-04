class TopVotedCandidate {
public:
    map<int, int> vote, winner;
    vector<int> time;
    
    int findTime(int t) {
        int left, right, mid;
        left = 0; right = time.size() - 1;
        
        while(left <= right) {
            mid = (left + right) / 2;
            
            if(time[mid] == t) return t;
            else if(time[mid] < t) left = mid + 1;
            else right = mid - 1;
        }
        
        return time[right];
    }
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int len = times.size();
        int per, maxVote = 0;
        for(int i=0 ; i<len ; i++ ) {
            vote[persons[i]]++;
            if(vote[persons[i]] > maxVote) {
                per = persons[i];
                maxVote = vote[persons[i]];
            }
            else if (vote[persons[i]] == maxVote) {
                per = persons[i];
            }
            
            winner[times[i]] = per;
        }
        
        for(int i=0 ; i<len ; i++ ) time.push_back(times[i]);
    }
    
    int q(int t) {
        int actualTime = findTime(t);
        cout << actualTime << endl;
        return winner[actualTime];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */