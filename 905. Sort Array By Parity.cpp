class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i, j, temp, len = nums.size();
        i = j = 0;
        while( j<len ) {
            if(nums[j] % 2 == 0) {
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                i++; j++;
            }
            else {
                j++;
            }
        }
        
        return nums;
    }
};
