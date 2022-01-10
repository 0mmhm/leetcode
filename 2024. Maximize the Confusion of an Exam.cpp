class Solution {
public:
    int maxAnswers(string str, char s, int k) {
        int left, right, flipped, maxRes, len = str.length();
        left = right = flipped = maxRes = 0;
        
        while(right < len) {
            if(str[right] == s) flipped++;
            while(flipped > k) {
                if(str[left] == s) flipped--;
                left++;
            }
            
            maxRes = max(maxRes, right-left+1);
            right++;
        }
        
        return maxRes;
    }
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        int flipT = maxAnswers(answerKey, 'T', k);
        int flipF = maxAnswers(answerKey, 'F', k);
        
        return max(flipT, flipF);
    }
};