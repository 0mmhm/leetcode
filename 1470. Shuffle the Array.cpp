class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector <int> res;
        int i, len = n;
        for( i=0 ; i<len ; i++ ){
            res.push_back(nums[i]);
            res.push_back(nums[n]);
            n++;
        }
        return res;
    }
};