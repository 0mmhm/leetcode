class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int i = 0, j = 1, val, res = 0, len = nums.size();
        
        while( i<len ) {
            res += nums[i];
            i += 2;
        }
        return res;
    }
};