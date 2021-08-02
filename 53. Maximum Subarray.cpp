class Solution {
public:
    
    // Kadane's Algorithm
    int maxSubArray(vector<int>& nums) {
        int len, i = 0;
        len = nums.size();
    
        int sum = 0; 
        int maxSum = nums[0];
        while( i<len ){
            sum += nums[i];
            if(sum > maxSum) maxSum = sum;
            
            if(sum < 0) sum = 0;
            i++;
        }
        return maxSum;
    }
};