class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        map <int, int> mp;
        map <int, int>::iterator it;
        
        for(int i=0 ; i<len ; i++) {
            mp[nums[i]] ++;
        }
        
        int sn = 0, res;
        k = len - k + 1;
    
        for(it = mp.begin() ; it != mp.end() ; it++) {
            int temp = it->second;
            sn += temp;
            if (sn >= k) {
                res = it->first;
                break;
            }
        }
        
        return res;
    }
};