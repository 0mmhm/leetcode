class Solution {
public:
    vector<string> res;
    map<string, int> mp;
    map<string, int>::iterator it;
    
    void separateCPDomain(string str) {
        int i, j, num, len = str.length();
        i = num = 0;
        vector<string> v;
        v.clear();
        
        stringstream check(str);
        string intermediate;
        while(getline(check, intermediate, ' ')) {
            v.push_back(intermediate);
        }
        
        num = stoi(v[0]);
        str = v[1];
        stringstream check1(str);
        v.clear();
        
        while(getline(check1, intermediate, '.')) {
            v.push_back(intermediate);
        }
        
        string s = "";
        for( i=v.size()-1 ; i>=0 ; i-- ) {
            s = "";   
            for( j=i ; j<v.size() ; j++) {
                if( j != i) s += ".";
                s += v[j];
            }
            mp[s] += num;
        }
    }
    
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        int i, len = cpdomains.size();
        res.clear();
        mp.clear();
        
        for( i=0 ; i<len ; i++ ) {
            separateCPDomain(cpdomains[i]);
        }
        
        string s, n;
        int num;
        for(it=mp.begin() ; it!=mp.end() ; it++) {
            s = it->first;
            num = it->second;
            n = to_string(num);
            
            res.push_back( n + " " + s );
        }
        
        return res;
    }
};