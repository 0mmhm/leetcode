class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int i, j, count, len = nums.size();
        vector <int> res;
        for( i=0 ; i<len ; i++ ) {
            count = 0;
            for( j=0 ; j<len ; j++ ) {
                if( i!=j && nums[i] > nums[j] ) {
                    count++;
                }
            }
            res.push_back(count);
        }
        return res;
    }
};