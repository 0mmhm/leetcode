class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxCont = -1, currCont, i, k, len = height.size();
        
        i = 0; k = len - 1;
        while( i < k ) {
            maxCont = max(maxCont, (min(height[i], height[k]) * (k - i)));
            
            if( i < k-1 ) {
                if(height[i] > height[k])
                    k--;
                else
                    i++;
            }
            else
                break;
        }
        
        return maxCont;
    }
};