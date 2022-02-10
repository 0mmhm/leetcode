class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minVal = 0, val = 0, len = nums.size();
        for(int i=0 ; i<len ; i++ ) {
            val += nums[i];
            minVal = min(minVal, val);
        }
        
        return abs(minVal) + 1;
    }
};