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
        string s = "";
        
        while(str[i] != ' '){ 
            num = (num*10) + (str[i++] - '0');
        }
        i++;
        
        s = "";
        while(i<len) {
            if(str[i] == '.') {
                v.push_back(s);
                s = "";
            }
            else {
                s += str[i];
            }
            i++;
        }
        v.push_back(s);
        for( i=v.size()-1 ; i>=0 ; i-- ) {
            s = "";   
            for( j=i ; j<v.size() ; j++) {
                if( j != i) s += ".";
                s += v[j];
            }
            mp[s] += num;
        }
    }
    
    string stringify(int num) {
        string s = "";
        int i;
        
        while(num > 0) {
            i = num % 10;
            num /= 10;
            s =  to_string(i) + s;
        }
        return s;
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
            n = stringify(num);
            
            res.push_back( n + " " + s );
        }
        
        return res;
    }
};