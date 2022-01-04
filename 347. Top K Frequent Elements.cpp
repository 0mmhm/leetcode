class Solution {
public:
    struct INFO {
        int num, freq;    
    };
    struct CompareHeight {
        bool operator()(INFO const& a, INFO const& b) {
            return a.freq < b.freq;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<INFO, vector<INFO>, CompareHeight> q;
        q = priority_queue<INFO, vector<INFO>, CompareHeight>();
        unordered_map<int, int> mp;
        
        int i, len = nums.size();
        for( i=0 ; i<len ; i++ ){
            mp[nums[i]]++;
        }
        
        INFO info;
        for(auto it=mp.begin() ; it!=mp.end() ; it++) {
            info.num = it->first;
            info.freq = it->second;
            
            q.push(info);
        }
        
        vector<int> res;
        res.clear();
        i = 0;
        while(i<k) {
            i++;
            res.push_back(q.top().num);
            q.pop();
        }
        
        return res;
    }
};