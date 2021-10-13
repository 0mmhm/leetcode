class Solution {
public:
    struct Node{
      vector<string> v;  
    }node[10009];
    
    map<string, int> mp;
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = 0;
        int i, j, len = strs.size();
        
        vector<char> temp;
        string str, oriStr;
        int strLen;
        for( i=0 ; i<len ; i++ ) {
            oriStr = str = strs[i];
            temp.clear();
            strLen = str.length();
            
            for( j=0 ; j<strLen ; j++ ) {
                temp.push_back(str[j]);
            }
            sort(temp.begin(), temp.end());
            
            str = "";
            for( j=0 ; j<strLen ; j++ ) {
                str += temp[j];
            }
            
            int ind = mp[str];
            if( ind != 0 ) {
                node[ind].v.push_back(oriStr);
            }
            else {
                n++;
                mp[str] = n;
                node[n].v.push_back(oriStr);
            }
            //cout << oriStr << " : " << str << " : " << ind << endl;
        }
        
        vector<vector<string>> res;
        for( i=1 ; i<=n ; i++ ) res.push_back(node[i].v);
        
        return res;
    }
};