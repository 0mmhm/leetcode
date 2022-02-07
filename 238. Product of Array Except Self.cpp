class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i, j, left, right, leftProduct, rightProduct, len = nums.size();
        vector<int> res(len, 1);
        
        i = 0; j = len-1;
        leftProduct = rightProduct = left = right = 1;
        
        while( i<len ) {
            leftProduct *= left;
            left = nums[i];
            
            rightProduct *= right;
            right = nums[j];
            
            res[i] *= leftProduct;
            res[j] *= rightProduct;
            i++; j--;
        }
        
        return res;
    }
};