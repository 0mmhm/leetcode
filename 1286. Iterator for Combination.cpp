class CombinationIterator {
public:
    string str;
    int strLen, len, counter, totComb;
    vector <string> v;
    
    void genCombinations(int id, string s) {
        if(s.length() == len) {
            v.push_back(s);
            return;
        }
        if(id >= strLen) return;
        
        genCombinations(id+1, s);
        genCombinations(id+1, (string)(s+str[id]));
    }
    
    CombinationIterator(string characters, int combinationLength) {
        str = characters;
        strLen = str.length();
        len = combinationLength;
        counter = totComb = 0;
        
        genCombinations(0, "");
        totComb = v.size();
        sort(v.begin(), v.end());
        for(int i=0 ; i<totComb ; i++ ) cout << v[i] << " " ;
        cout << endl;
    }
    
    string next() {
        counter++;
        return v[counter-1];
    }
    
    bool hasNext() {
        if(counter<totComb) return true;
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */