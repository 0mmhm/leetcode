class Solution {
public:
    map<int, int> mp;
    
    int findMaxLength(vector<int>& nums) {    
        int count = 0, i, len = nums.size();
        int prevIndex, maxLen = 0;
        
        mp[0] = 0;
        for( i=1 ; i<=len ; i++ ) {
            if(nums[i-1] == 0) count -= 1;
            else count += 1;
            
            if(count == 0 || mp[count] != 0) {
                prevIndex = mp[count];
                if(prevIndex == -1) prevIndex = 0;
                maxLen = max(maxLen, i - prevIndex);        
            }
            else  mp[count] = i;
            
        }
        
        return maxLen;
    }
};