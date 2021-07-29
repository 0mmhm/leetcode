class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int i, freq, val, len = nums.size();
        vector <int> res;
        
        for( i=0 ; i<len ; i++ ){
            freq = nums[i];
            val = nums[i+1];
            i++;
            
            while(freq--){
                res.push_back(val);
            }
        }
        return res;
    }
};