class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int len = seats.size();
        int i, left, right, maxDistance = -1;;
        left = right = -1;
        
        for( i=0 ; i<len ; i++ ) {
            if(seats[i] == 1) {
                right = i;
                if(left != -1) 
                    maxDistance = max(maxDistance, (right-left)/2);
                else 
                    maxDistance = max(maxDistance, right);
                    
                //cout << i << " = " << maxDistance << endl;
                left = right;
            }
        }
        
        if(seats[len-1] != 1) {
            maxDistance = max(maxDistance, (len-1 - left));
        }
        
        return maxDistance;
        
    }
};