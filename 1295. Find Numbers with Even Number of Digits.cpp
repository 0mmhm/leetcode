class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int i, len = nums.size();
        
        int digit, res = 0;
        for( i=0 ; i<len ; i++ ){
            digit = log10(nums[i]) + 1;
            if(digit % 2 == 0) res++;
        }
        
        return res;
    }
};