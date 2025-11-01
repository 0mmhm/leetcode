class Solution {
public:
    int jump(vector<int>& nums) {
        int i, len, currpos, maxpos, jump;
        currpos, maxpos, jump = 0;
        len = nums.size();

        for( i=0 ; i<len-1 ; i++) {
            maxpos = max(maxpos, i+nums[i]);
            if(i == currpos) {
                currpos = maxpos;
                jump++;
                if(currpos>=len-1) break;
            }
        }

        return jump;
    }
};
