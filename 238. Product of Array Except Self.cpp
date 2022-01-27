class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i, zero = 0, len = nums.size();
        int product = 1;
        
        for( i=0 ; i<len ; i++ ) {
            if(nums[i] == 0) zero++;
            if(nums[i] != 0) product *= nums[i];
        }
        
        for( i=0 ; i<len ; i++ ) {
            if(zero > 1) {
                nums[i] = 0;
            }
            else if(zero == 1) {
                if(nums[i] != 0) nums[i] = 0;
                else nums[i] = product;
            }
            else {
                nums[i] = product / nums[i];
            }
        }
        
        return nums;
    }
};