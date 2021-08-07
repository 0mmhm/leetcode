class MapSum {
public:
    /** Initialize your data structure here. */
    map <string, int> mp, keyExist;
    MapSum() {
        mp.clear();
        keyExist.clear();
    }
    
    void insert(string key, int val) {
        int subtractVal, len = key.length();
        subtractVal = 0;
        if(keyExist[key] > 0) {
            subtractVal = keyExist[key];
        }
        keyExist[key] = val;
        
        string prefix = "";
        for(int i=0 ; i<len ; i++ ) {
            prefix += key[i];
            // if(prefix == "ap") cout << mp[prefix] << " : " << val << " : " << subtractVal << endl;
            mp[prefix] = mp[prefix] +  val - subtractVal;
            // if(prefix == "ap") cout << mp[prefix] << endl;
        }
    }
    
    int sum(string prefix) {
        return mp[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */