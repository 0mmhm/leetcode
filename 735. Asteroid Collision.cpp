class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int i, top, curr, n = 0, len = asteroids.size();
        
        i = 0;
        while(i<len) {
            curr = asteroids[i];
            
            if((st.empty() || curr > 0) || (curr < 0 && !st.empty() && st.top() < 0) ) {
                st.push(curr);
                n++;
            }
            else {
                curr = abs(curr);
                bool discardedAll;
                
                while(!st.empty()) {
                    discardedAll = false;
                    top = st.top();
                    
                    if(top < 0) {
                        st.push(curr*-1);
                        n++;
                        break;
                    }
                    if(curr > top) {
                        st.pop();
                        n--;
                        discardedAll = true;
                    }
                    else if(curr == top) {
                        st.pop();
                        n--;
                        break;
                    }
                    else{
                        break;
                    }
                }
                if(discardedAll) { st.push(curr*-1); n++; }
            }
            i++;
        }
        
        vector<int> res(n);
        for( i=n-1 ; i>=0 ; i-- ) {
            res[i] = st.top(); st.pop();
        }
        
        return res;
    }
};