class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, j, zero = 0, len = nums.size();
        i = j = 0;
        while( j<len ) {
            if(nums[j] == 0) {
                zero++;
                j++;
            }
            else if(i<j) {
                while(j<len && i<j && nums[j] != 0) {
                    nums[i] = nums[j];
                    i++;
                    j++;
                }
            }
            else{
                i++;
                j++;
            }
            
        }
        
        while(i<len) nums[i] = 0, i++;
        
    }
};