class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i, k, sum = 0, minLen = 100009, len = nums.size();
        i = 0; k = -1;
        
        while(i<len-1) {
            if(i>=k || (k<len-1 && sum<target)) {
                k++;
                sum += nums[k];
            }
            else {
                sum -= nums[i];
                i++;
            }
            
            if(sum >= target)
                minLen = min(minLen, k - i + 1);
            
            cout << i << " " << k << endl;
        }
        
        return minLen == 100009 ? 0 : minLen;
    }
};