class Solution {
public:
    map<int, int> mp;
    int subarraySum(vector<int>& nums, int k) {
        int i,mapSum, sum = 0, res = 0, len = nums.size();
        mp[0] = 1;
        for( i=0 ; i<len ; i++ ){
            sum += nums[i];
            
            if(mp[sum-k]>0){
                res += mp[sum-k];
            }
            
            mp[sum]++;
        }
        return res;
    }
};