
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int len = deck.size();
        int i, ind;
        deque<int> dq;
        
        for( i=0 ; i<len ; i++ ) dq.push_back(i);
        sort(deck.begin(), deck.end());
        
        vector<int> index, res(len);
        while(!dq.empty()) {
            ind = dq.front(); dq.pop_front();
            index.push_back(ind);
            
            if(!dq.empty()) {
                ind = dq.front(); dq.pop_front();
                dq.push_back(ind);
            }
        }
        
        for( i=0 ; i<len ; i++ ) {
            res[index[i]] = deck[i];
        }
        
        return res;
    }
};