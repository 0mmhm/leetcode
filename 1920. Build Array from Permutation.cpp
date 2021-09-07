class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int i, len = nums.size();
        for( i=0 ; i<len ; i++ ) {
            nums[i] += len * (nums[nums[i]] % len);
        }
        
        for( i=0 ; i<len ; i++ ) {
            nums[i] /= len;
        }
        
        return nums;
    }
};