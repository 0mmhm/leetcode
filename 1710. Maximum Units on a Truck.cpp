class Solution {
public:
    
    vector<pair<int, int>> vp;
    
    static bool sortBox(const pair<int,int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int i, len = boxTypes.size();
        for( i=0 ; i<len ; i++ ) {
            vp.push_back(make_pair(boxTypes[i][0], boxTypes[i][1]));
        }
        
        sort(vp.begin(), vp.end(), sortBox);
        
        int loadedSize = 0, totalUnit = 0;;
        for( i=0 ; i<len ; i++ ) {
            if( loadedSize + vp[i].first <= truckSize ) {
                loadedSize += vp[i].first;
                totalUnit += (vp[i].first * vp[i].second);
            }
            else {
                totalUnit += ( truckSize - loadedSize ) * vp[i].second;
                break;
            }
        }
        
        return totalUnit;
    }
};