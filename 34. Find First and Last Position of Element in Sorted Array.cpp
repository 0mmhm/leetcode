class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left, right, mid, len = nums.size();
        vector <int> res;
        
        left = 0; right = len - 1;
        int leftIndex = -1;
        while(left <= right){
            mid = (left + right) / 2;
            if(nums[mid] == target){
                leftIndex = mid;
                right = mid - 1;
            }
            else if(nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        
        if(leftIndex == -1){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        
        left = 0; right = len - 1;
        int rightIndex;
        while(left <= right){
            mid = (left + right) / 2;
            if(nums[mid] == target){
                rightIndex = mid;
                left = mid + 1;
            }
            else if(nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        
        res.push_back(leftIndex);
        res.push_back(rightIndex);
        return res;
    }
};