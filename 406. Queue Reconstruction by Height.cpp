class Solution {
public:
    struct INFO {
        int h, k;
        
        INFO(int h, int k): h(h), k(k) {
            
        }
    };
    
    struct compare{
        bool operator()(INFO const& a, INFO const& b) {
            if( a.h < b.h ) return true;
            else if(a.h == b.h && a.k > b.k) return true;
                
            return false;
        }  
    };
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        priority_queue<INFO, vector<INFO>, compare> pq;
        pq = priority_queue<INFO, vector<INFO>, compare>();
        
        int i, len = people.size();
        for( i=0 ; i<len ; i++ ) {
            pq.push(INFO(people[i][0], people[i][1]));
            people[i][0] = people[i][1] = -1;
        }
        
        
        INFO I = INFO(0, 0);
        while(!pq.empty()) {
            I = pq.top(); pq.pop();
            
            if( people[I.k][0] == -1) {
                people[I.k][0] = I.h;
                people[I.k][1] = I.k;
            }
            else{
                int end = len;
                for( i=end-1 ; i>I.k ; i-- ) {
                    people[i][0] = people[i-1][0];
                    people[i][1] = people[i-1][1];
                }
                people[I.k][0] = I.h;
                people[I.k][1] = I.k;
            }
        }
        
        return people;
    }
};