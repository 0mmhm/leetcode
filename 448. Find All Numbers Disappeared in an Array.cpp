class Solution {
public:
    vector<int> res;
    
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i, len = nums.size();
        int it = 0;
        for( i=0 ; i<len ; i++ ) {
           if(nums[i] != i+1) {
               int a, b, k = i, rep;
               while(nums[k] != k+1) {
                   rep = nums[k];
                   a = nums[k];
                   b = nums[a-1];
                   
                   nums[a-1] = a;
                   nums[k] = b;
                   if(rep == nums[k]) break;
               }
           }
        }
        
        for( i=0 ; i<len ; i++ ) {
            if(nums[i] != i+1) res.push_back(i+1);
        }    
        
        return res;
    }
};