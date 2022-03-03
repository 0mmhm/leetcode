class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> fact;
        int i;
        for( i=1 ; i<=n ; i++ ) {
            if(!(n%i)) fact.push_back(i);
        }
        
        if(fact.size() < k) return -1;
        return fact[k-1];
    }
};