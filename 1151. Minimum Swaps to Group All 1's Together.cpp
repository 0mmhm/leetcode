class Solution {
public:
    int minSwaps(vector<int>& data) {
        int i, j, totalOne = 0, zero = 0, len = data.size();
        
        for( i=0 ; i<len ; i++ ) {
            if(data[i] == 1) totalOne++;
        }
        if(totalOne == 0) return 0;
        
        i = j = 0;
        while(j<=totalOne-1) if(data[j++] == 0) zero++;
        j = totalOne - 1;
        
        int swap = 100009;
        while( j<len ) {
            if(swap > zero) swap = zero;
            
            if(!data[i]) zero--;
            i++;
            j++;
            if(j < len && !data[j]) zero++;
        }
        
        return swap;
    }
};