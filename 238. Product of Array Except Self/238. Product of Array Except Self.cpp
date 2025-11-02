class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i, len = nums.size();
        vector <int> res (len, 1);
        

        for( i=1 ; i<len ; i++ ) {
            res[i] = res[i-1] * nums[i-1];
        }

        int temp = nums[len-1];
        for( i=len-2 ; i>=0 ; i-- ){
            res[i] *= temp;
            temp *= nums[i];
        }

        return res;
    }
};