class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> v(26);
        map<char, int> mp;
        int i, j, k, val, len = s.length();
        vector<int> res, uniq;
        
        for( i=0 ; i<len ; i++ ) {
            val = s[i] - 'a';
            v[val].push_back(i);
            
            if(mp[s[i]] == 0) {
                uniq.push_back(val);
            }
            mp[s[i]] = 1;
        }
        
        int a, b, startFind = -1, firstPos, lastPos, charVal, uniqLen = uniq.size();
        for( i=0 ; i<uniqLen ; i++ ) {
            charVal = uniq[i];
            firstPos = v[charVal][0];
            lastPos = v[charVal][ v[charVal].size() - 1 ];
            
            for( k=0 ; k<26 ; k++ ) {
                for( j=0 ; j<26 ; j++ ) {
                    if(mp[ j + 'a' ] > 0) {
                        a = v[j][0]; b = v[j][ v[j].size() - 1 ];
                        if(a>firstPos &&  a < lastPos && b > lastPos ) lastPos = b;
                    }
                }
            }
            
            if( firstPos >= startFind ) {
                res.push_back(lastPos + 1 - (startFind + 1));
                startFind = lastPos;
            }
        }
       
        return res;
    }
};