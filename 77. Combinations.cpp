class Solution {
public:
    vector<vector<int>> com;
    
    void genCombinations(vector<int> v, int num, int end, int count, int k) {
        if(count == k){
            com.push_back(v);
            return;
        }
        
        // k-count>0 condition will also solve the problem but it will call/try all the combination and filter k length combinations
        // on '0' indexed array, The condition "end-i+1 >= r-index" makes sure that including one element
        // - at index will make a combination with remaining elements at remaining positions
        for(int i=num ; i<=end && end-i+1 >= k-count ; i++ ) { 
           v.push_back(i);
           genCombinations(v, i+1, end, count+1, k);
           v.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        v.clear();
        com.clear();
        
        genCombinations(v, 1, n, 0, k);
        
        return com;
    }
};