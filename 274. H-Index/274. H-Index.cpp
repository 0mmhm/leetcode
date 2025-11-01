class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        int hIndex = 0, rank = 1, i, len = citations.size();
        for(i=len-1 ; i>=0 ; i-- ) {
            if (citations[i] >= rank++) hIndex++;
            else break;
        }

        return hIndex;
    }
};
