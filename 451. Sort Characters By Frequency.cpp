class Solution {
public:
    struct INFO{
        char c;
        int freq;
    };
    
    INFO info[80];
    
    string frequencySort(string s) {
        map <char, int> mp;
        map <char, int>::iterator it;
        int i, j, cnt, len = s.length();
        
        for( i=0 ; i<80 ; i++ ) info[i].freq = 0;
        
        for( i=0 ; i<len ; i++ ) {
            mp[s[i]]++;
        }
        
        string res = "";
        char ch;
        
        i = 0;
        for( it=mp.begin() ; it!=mp.end() ; it++ ) {
            info[i].c = it->first;
            info[i].freq = it->second;
            i++;
        }
        
        int limit = i;
        
        for( i=0 ; i<limit-1 ; i++ ) {
            for( j=0 ; j<limit-1 ; j++ ) {
                if( info[j].freq < info[j+1].freq ) {
                    int temp = info[j].freq;
                    info[j].freq = info[j+1].freq;
                    info[j+1].freq = temp;
                    
                    char x = info[j].c;
                    info[j].c = info[j+1].c;
                    info[j+1].c = x;
                }
            }
        }
        
        for( i=0 ; i<limit ; i++ ) {
            for( j=0 ; j<info[i].freq ; j++ ) res += info[i].c;
        }
        
        return res;
    }
};