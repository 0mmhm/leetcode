class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector <int> res;
        int i, len = nums.size();
        for( i=0 ; i<len ; i++ ) res.push_back(nums[i]);
        for( i=0 ; i<len ; i++ ) res.push_back(nums[i]);
        return res;
    }
};