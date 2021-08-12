class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int i, j, len = rectangles.size();
        
        vector<int> sqRec;
        for( i=0 ; i<len ; i++ ){
            sqRec.push_back( min(rectangles[i][0], rectangles[i][1]) );
        }
        
        sort(sqRec.begin(), sqRec.end());
        int maxLen, sqRecLen = sqRec.size();
        maxLen = sqRec[ sqRecLen - 1];
        
        int res = 0;
        for( j=sqRecLen - 1 ; j>=0 ; j--){
            if(sqRec[j] == maxLen) res++;
        }
        return res;
    }
};