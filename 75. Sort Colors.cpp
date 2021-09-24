class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i, j, k, len = nums.size();
        int a;
        
        for( i=0 ; i<len ; i++ ) {
            a = nums[i];
            j = 0;
            while( j<i && j<len &&  nums[j] <= a) j++;
            
            for( k= i-1 ; k>=j ; k--) {
                nums[k + 1] = nums[k];
            }
            nums[j] = a;
        }
    }
}