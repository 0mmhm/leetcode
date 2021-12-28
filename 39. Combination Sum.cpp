class Solution {
public:
    vector<vector<int>> res;
    
    void findCombinationSum(vector<int>& arr,int start, int len, vector<int>& v, int target, int sum) {
        if(sum > target) return;
        
        if(sum == target) {
            res.push_back(v);
            return;
        }
        
        for(int i=start ; i<len ; i++) {
            v.push_back(arr[i]);
            findCombinationSum(arr, i, len, v, target, sum+arr[i]);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        v.clear();
        res.clear();
        
        findCombinationSum(candidates, 0, candidates.size(), v, target, 0);
        
        return res;
    }
};