class Solution {
public:
    vector <vector<int>> per; 
    vector <int> v;
    
    void getPermutations(vector<int>& nums, int ind, int len) {
        if(ind == len) {
            v.clear();        
            for(int i=0 ; i<len ; i++ ) v.push_back(nums[i]);
            per.push_back(v);
            return;
        }
        
        for(int i=ind ; i<len ; i++ ) {
            swap(nums[ind], nums[i]);
            getPermutations(nums, ind+1, len);
            swap(nums[ind], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        getPermutations(nums, 0, nums.size());
        
        return per;
    }
};