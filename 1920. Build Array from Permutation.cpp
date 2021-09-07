class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int i, len = nums.size();
        vector<int> res;
        for( i=0 ; i<len ; i++ ) {
            res.push_back(nums[nums[i]]);
        }
        
        return res;
    }
};