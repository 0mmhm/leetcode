class Solution {
public:
    int findMin(vector<int>& nums) {
        int left, right, mid, len = nums.size();
        left = 0; right = len - 1;
        
        int minNum;
        while(left <= right){
            mid = (left + right) / 2;
            cout << "left: " << left << " , mid: " << mid << " right: " << right << endl;
            
            if(nums[left] <= nums[mid] && nums[mid] >= nums[len-1] && nums[left] > nums[len-1] ) {
                left = mid + 1;
            }
            else if(nums[left] >= nums[mid] && nums[mid] <= nums[len-1] && nums[left] > nums[len-1]) {
                if(nums[mid] < minNum) minNum = nums[mid];
                right = mid - 1;
            }
            else if(nums[left] <= nums[right]) {
                if(nums[left] < minNum) minNum = nums[left];
                break;
            }
        }
        
        return minNum;
    }
};