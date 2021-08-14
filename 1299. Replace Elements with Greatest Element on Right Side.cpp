class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int len = arr.size();
        int temp, currMax = arr[len-1];
        arr[len-1] = -1;
        
        for(int i=len-2 ; i>=0 ; i--) {
            temp = currMax;
            currMax = max(currMax, arr[i]);
            arr[i] = temp;
        }
        
        return arr;
    }
};