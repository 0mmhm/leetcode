class TweetCounts {
public:
    vector <vector<int>> record;
    unordered_map <string, int> mp;
    int serial;
    
    TweetCounts() {
        serial = 0;
        record.clear();
        mp.clear();
    }
    
    void recordTweet(string tweetName, int time) {
        if(mp[tweetName] == 0) {
            serial++;
            mp[tweetName] = serial;
            vector <int> v;
            v.clear();
            v.push_back(time);
            record.push_back(v);
        }
        else{
            int ind = mp[tweetName] - 1;
            record[ind].push_back(time);
        }
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int timeDif;
        if(freq == "minute")
            timeDif = 60;
        else if(freq == "hour")
            timeDif = 3600;
        else timeDif = 86400;
        
        int i = 0, ind, len;
        ind = mp[tweetName] - 1;
        len = record[ind].size();
        
        sort(record[ind].begin(), record[ind].end());
        
        while(i<len && record[ind][i] < startTime)
            i++;
       
        vector <int> res;
        int count = 0;
        while(startTime <= endTime) {
            count = 0;
            while(i<len && record[ind][i] < startTime+timeDif && record[ind][i] <= endTime) {
                count++;
                i++;
            }
            res.push_back(count);
            startTime += timeDif;
        }
        
        if(res.size() == 0) res.push_back(0);
        return res;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */