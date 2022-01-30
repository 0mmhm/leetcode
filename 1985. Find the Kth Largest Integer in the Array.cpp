class Solution {
public:
    
    struct INFO{
        string s;
        
        INFO(string s): s(s) {
            
        }
    };
    
    struct compare{
        bool operator()(INFO const& a, INFO const& b) {
            string x, y;
            x = a.s; y = b.s;
            int lenx = x.length(), leny = y.length();
            
            if(lenx < leny) return true;
            else if(leny < lenx) return false;
            else{
                for(int i=0 ; i<lenx ; i++ ) {
                    if(x[i] < y[i]){
                        return true;
                    }
                    else if(x[i] > y[i]) return false;
                }
            }
            return false;
        }
    };
    
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<INFO, vector<INFO>, compare> pq;
        pq = priority_queue<INFO, vector<INFO>, compare>();
        
        int i, len = nums.size();
        for( i=0 ; i<len ; i++ ) {
            pq.push(INFO(nums[i]));
        }
        
        i = 0;
        INFO I = INFO("");
        while(!pq.empty()) {
            I = pq.top();
            pq.pop();
            
            cout << I.s << endl;
            
            i++;
            if(i == k) break;
        }
        
        return I.s;
    }
};