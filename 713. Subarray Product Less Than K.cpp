class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int pro, res, left = 0, len = nums.size();
        res = 0;
        pro = 1;
        
        for(int i=0 ; i<len ; i++ ) {
            pro *= nums[i];
            while(pro >= k && left<=i) pro /= nums[left++];
            res += i - left + 1;
        }
        
        return res;
    }
};