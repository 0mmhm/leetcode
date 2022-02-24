class Solution {
public:
    int addSummationToN(int n) {
        n--;
        
        int nn = n + 1;
        if(n%2) {
            nn /= 2;
        }
        else {
            n /= 2;
        }
        
        return n * nn;
    }
    
    int numPairsDivisibleBy60(vector<int>& time) {
        int i, j, mod[60], len = time.size();
        
        for( i=0 ; i<60 ; i++ ) mod[i] = 0;
        for( i=0 ; i<len ; i++ ) mod[time[i] % 60]++;
        
        int pair = 0;
        if(mod[0] > 1) pair +=  addSummationToN(mod[0]);
        if(mod[30] > 1) pair +=  addSummationToN(mod[30]);
        
        
        for( i=0 ; i<60 ; i++ ) {
            for( j=i+1 ; j<60 ; j++ ) {
                if(mod[i] && mod[j] && i + j == 60) {
                    pair += mod[i]* mod[j];
                }
            }
        }
        
        return pair;
    }
};