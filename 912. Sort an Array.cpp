class Solution {
public:
    void mergeSort(vector<int>& v, int temp[], int lo, int hi) {
        if(lo == hi) return;
        
        int mid = (lo + hi) / 2;
        
        mergeSort(v, temp, lo, mid);
        mergeSort(v, temp, mid+1, hi);
        
        int i = lo, j = mid+1, k = lo;
        while(i<=mid && j<=hi) {
            if(v[i] <= v[j]) temp[k++] = v[i++];
            else temp[k++] = v[j++];
        }
        
        while(i<=mid) temp[k++] = v[i++];
        while(j<=hi) temp[k++] = v[j++];
        
        for( i=lo ; i<=hi ; i++ ) v[i] = temp[i];
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int len = nums.size();
        int temp[len];
        
        mergeSort(nums, temp, 0, len-1);
        return nums;
    }
};