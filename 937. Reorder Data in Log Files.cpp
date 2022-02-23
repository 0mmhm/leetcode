class Solution {
public:
    struct LETTERLOGS {
        string identifier, content;  
    };
    
    static bool compare(const LETTERLOGS& a, const LETTERLOGS& b) {
        if( a.content < b.content ) return true;
        else if(a.content == b.content && a.identifier < b.identifier) return true;

        return false;
    }  

    
    int ind;
    LETTERLOGS llogs[109];
    vector<string> dlogs;
    
    void splitLog(string str) {
        string temp = "";
        int i, len = str.length();
        
        bool mark = false, isDigitLog = false;
        for( i=0 ; i<len ; i++ ) {
            if(mark && str[i] >= '0' && str[i] <= '9') isDigitLog = true;
            if(mark || str[i] != ' ') temp += str[i];
            else {
                mark = true;
                llogs[ind].identifier = temp;
                temp = "";
            }
        }
        if(isDigitLog) {
            ind--;
            dlogs.push_back(str);
        }
        else llogs[ind].content = temp;
        ind++;
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        int i, len = logs.size();
        
        
        ind = 0;
        for( i=0 ; i<len ; i++ ) splitLog(logs[i]);
        
        sort(llogs, llogs+ind, compare);
        
        vector<string> res;
        string temp;
        for( i=0 ; i<ind ; i++ ) {
            temp = llogs[i].identifier + " " + llogs[i].content;
            res.push_back(temp);
        }
        int dlogsLen = dlogs.size();
        for( i=0 ; i<dlogsLen ; i++ ) res.push_back(dlogs[i]);
        
        return res;
    }
};