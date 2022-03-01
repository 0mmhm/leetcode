class Solution {
public:
    vector<int> pre, post, mid;

    int findMinSwap(vector<int>& v) {
        int i, j, zero = 0, totalOne = 0, minSwap = 100009, len = v.size();
            
        for( i=0 ; i<len ; i++ ) if(v[i]) totalOne++;
        
        if(totalOne == 0) return 0;
        i = j = 0;
        while(j<totalOne) if(!v[j++]) zero++;
        j--;
        
        while(i<len) {
            minSwap = min(minSwap, zero);
            if(!v[i]) zero--;
            i++;
            j++;
            if(j>=len) j = j - len;
            if(j<len && !v[j]) zero++;
        }
        
        return minSwap;
    }

    int minSwaps(vector<int>& nums) {    
        return findMinSwap(nums);
    }
};