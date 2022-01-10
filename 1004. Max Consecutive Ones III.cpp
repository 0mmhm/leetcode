class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxOne, ones, left, right, flipped, len = nums.size();
        left = right = maxOne = ones = flipped = 0; 
        
        while(right < len) {
            if(nums[right] == 0) flipped++;
            while(flipped > k) {
                if(nums[left] == 0) flipped--;
                left++;
            }
            
            maxOne = max(maxOne, right-left + 1);
            right++;
        }
        
        return maxOne;
    }
};