class Solution {
public:
    string getHint(string secret, string guess) {
        int mpSecret[10], mpGuess[10], mp[10];
        int i, len = secret.length();
        int bulls, cows;
        bool mark[len];
        
        for( i=0 ; i<10 ; i++ ) mpSecret[i] = mpGuess[i] = mp[i] = 0;
        for( i=0 ; i<len ; i++ ) mark[i] = false;
        bulls = cows = 0;
        
        for( i=0 ; i<len ; i++ ){
            if( secret[i] == guess[i]) {
                bulls++;
                mark[i] = true;
            }
            else {
                mpSecret[secret[i] -'0']++;
                mpGuess[guess[i] -'0']++;
            }
        }
        
        for( i=0 ; i<len ; i++ ){
            if(!mark[i] && mp[guess[i] -'0'] == 0) {
                mp[guess[i] -'0'] = 1;
                cows += min(mpSecret[guess[i] -'0'], mpGuess[guess[i] -'0']);
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

/*
class Solution {
public:
    string getHint(string secret, string guess) {
        map<char, int> mpSecret, mpGuess, mp;
        int i, len = secret.length();
        
        int bulls, cows;
        bulls = cows = 0;
        mpSecret.empty();
        mpGuess.empty();
        
        bool mark[len];
        for( i=0 ; i<len ; i++ ) mark[i] = false;
        
        for( i=0 ; i<len ; i++ ){
            if( secret[i] == guess[i]) {
                bulls++;
                mark[i] = true;
            }
            else {
                mpSecret[secret[i]]++;
                mpGuess[guess[i]]++;
            }
        }
        
        for( i=0 ; i<len ; i++ ){
            if(!mark[i] && mp[guess[i]] == 0) {
                mp[guess[i]] = 1;
                cows += min(mpSecret[guess[i]], mpGuess[guess[i]]);
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
*/