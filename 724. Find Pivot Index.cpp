class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i, j, len = nums.size();
        
        if(len == 1) return 0;
        
        int left[len], right[len];
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
        
        i = 1;
        j = len-2;
        left[0] = nums[0]; right[len-1] = nums[len-1];
        while(i<len) {
            left[i] = nums[i] + left[i-1];
            right[j] = nums[j] + right[j+1];
            
            i++;
            j--;
        }
        
        for( i=0 ; i<len ; i++ ) {
            if(i-1<0 && i+1<len) {
                if(right[i+1] == 0) return i;
            }
            else if(i-1>=0 && i+1==len) {
                if(left[i-1] == 0) return i;
            }
            else if( left[i-1] == right[i+1] ) return i;
        }
        
        return -1;
    }
};