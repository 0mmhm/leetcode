class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i, len = nums.size();
        
        vector<int> v(len + 1, -1);
        
        for( i=0 ; i<len ; i++ ) {
            if(nums[i] > 0 && nums[i]<=len) {
                v[nums[i]] = 1;
            }
        }
        
        int smallestMissingPositive = len + 1;
        for( i=1 ; i<len+1 ; i++ ){
            if(v[i] == -1){
                smallestMissingPositive = i;
                break;
            }
        }
        
        return smallestMissingPositive;
    }
};

/* my solution
class Solution {
public:
    #define SIZE 5*100009
    
    unordered_map<int, int> mp;
    int firstMissingPositive(vector<int>& nums) {
        int i, len = nums.size();
        
        for( i=0 ; i<len ; i++ ) {
            if(nums[i] > 0) {
                mp[nums[i]] = 1;
            }
        }
        
        int smallestMissingPositive;
        for( i=1 ; i<=SIZE ; i++ ){
            if(mp[i] == 0){
                smallestMissingPositive = i;
                break;
            }
        }
        
        return smallestMissingPositive;
    }
};
*/

/* leetcode solution with O(n) time complexity & O(1) space complexity
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i, n = nums.size();
        bool isOneFound = false;
        
        for( i=0 ; i<n ; i++ ) {
            if(nums[i] == 1) isOneFound = true;
            
            if(nums[i] < 1 || nums[i] > n) {
                nums[i] = 1;
            }
        }
        
        if(!isOneFound) return 1;
        
        for( i=0 ; i<n ; i++ ) {
            int ind = abs(nums[i]);
            
            if(ind < n) {
                nums[ind] = -1 * abs(nums[ind]);
            }
            else {
                nums[0] = n * -1;
            }
        }
        
        for( i=1 ; i<n; i++ ){
            if(nums[i] > 0) return i;
        }
        
        if(nums[0] > 0) return n;
        
        return n+1;
    }
};
*/