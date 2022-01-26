class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i, safeTill = 0, len = nums.size();
        if(len == 1) return true;
        
        safeTill = nums[0];
        i = 0;
        while(i <= safeTill) {
            if(safeTill>=len-1) return true;
            
            safeTill = max(safeTill, (i+nums[i]));
            i++;
        }
        
        return false;
    }
};