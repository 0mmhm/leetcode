class NumArray {
public:
    vector<int> leftv;
    
    NumArray(vector<int>& nums) {
        int i, j, len = nums.size();
        i = 0; j = len-1;
        
        while( i< len) {
            if( i==0 ) leftv.push_back(nums[i]);
            else {
                leftv.push_back(nums[i] + leftv[i-1]);
            }
            
            i++;
        }
    }
    
    int sumRange(int left, int right) {
        int res = leftv[right];
        if(left-1 >= 0) res -= leftv[left-1];
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */