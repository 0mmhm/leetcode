class Solution {
public:
    struct INFO {
        string word;
        int freq;
    };
    
    struct CompareFreq {
        bool operator()(INFO const& a, INFO const& b) {
            if (a.freq < b.freq) return true;
            else if(a.freq == b.freq && a.word > b.word) return true;
            
            return false;
        }
    };
    
    unordered_map<string, int> mp;
    priority_queue<INFO, vector<INFO>, CompareFreq> pq;
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        pq = priority_queue<INFO, vector<INFO>, CompareFreq>();
        
        int i, len = words.size();
        for( i=0 ; i<len ; i++ ) {
            mp[words[i]]++;
        }
        
        INFO info;
        for(auto it=mp.begin() ; it!=mp.end() ; it++) {
            info.word = it->first;
            info.freq = it->second;
            pq.push(info);
        }
        
        vector<string> res;
        res.clear();
        i = 0;
        while( i<k ) {
            i++;
            res.push_back(pq.top().word);
            pq.pop();
        }
        
        return res;
    }
};