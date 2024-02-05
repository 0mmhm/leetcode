class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        int i, left, right;
        map<int, int> mp;
        for( i=0 ; i<len ; i++ ){
            mp[nums[i]] = i+1;
        }
        
        for( i=0 ; i<len ; i++ ){
            left = nums[i];
            right = target - nums[i];
            if(mp[right] > 0){
                left = i;
                right = mp[right] - 1;
                if(left != right) break;
            }
        }
        
        vector<int> res;
        res.push_back(left);
        res.push_back(right);
        return res;
    }
};
