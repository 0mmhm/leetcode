class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Floyd's Tortoise and Hare (Cycle Detection)
        int tortoise, hare;
        tortoise = hare = nums[0];
        
        tortoise = nums[tortoise]; // 1 step
        hare = nums[nums[hare]];   // 2 step
        
        while(tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }
        
        tortoise = nums[0];
        while(tortoise != hare){
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        
        return hare;
        
        /*
        // Time Complexity: O(n log n)
        // Space Complexity: 
        
        map <int, int>mp;
        int res = 0,len = nums.size();
        
        for(int i=0 ; i<len ; i++ ){
            if(mp[nums[i]] > 0){
                res = nums[i];   
                break;
            }
            mp[nums[i]]++;
        }
        return res;
        */
    }
};