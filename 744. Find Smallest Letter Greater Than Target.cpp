class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i, len = letters.size();
        
        for( i=0 ; i<len ; i++ ){
            if( letters[i] > target ){
                return letters[i];
            }
        }
        return letters[0];
    }
};