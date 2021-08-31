class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if( k== 1) return 0;
        
        sort(nums.begin(), nums.end());
        int i, dif, res = 100009, len = nums.size();
        
        i = 0; k--;
        while(k<len) {
            dif = nums[k] - nums[i];
            i++; k++;
            res = min(res, dif);
        }
        
        return res;
    }
};