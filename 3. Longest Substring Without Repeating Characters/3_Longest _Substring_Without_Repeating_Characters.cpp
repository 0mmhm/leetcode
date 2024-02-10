class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map <char, int> mp;
        deque <char> dq;
        
        int i, maxlen = 0, currlen = 0, len = s.length();
        char ch, tmp;
        
        mp.clear();
        for( i=0 ; i<len ; i++ ) {
            ch = s[i];
            mp[ch]++;
            dq.push_back(ch);
            currlen++;
            
            if (mp[ch] == 1) { 
                maxlen = max(maxlen, currlen);
            }
            else if(mp[ch] > 1) {
                while( !dq.empty() ) {
                    tmp = dq.front(); dq.pop_front();
                    mp[tmp]--;
                    currlen--;
                    if(tmp == ch)
                        break;
                }
            }
        }
        
        return maxlen;
    }
};