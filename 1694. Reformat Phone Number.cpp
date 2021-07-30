class Solution {
public:
    string reformatNumber(string number) {
        string res = "";
        int i, j, k, len = number.length();
        for( i=0 ; i<len ; i++ ) {
            if(number[i] >= '0' && number[i]<='9') res += number[i];
        }
        
        i = 0;
        len = res.length();
        string ans = "";
        while(i<len) {
            if(i != 0) ans += '-';
            int left = len - i;
            cout << left << " " << i << endl;
            if(left > 4) {
                j = i + 3;
                while(i<j){
                    ans += res[i++];
                }
            }
            else if(left == 4){
                k = 1;
                for(j=i ; j<=i+3 ; j++){
                    if(k == 3) ans += '-';
                    ans += res[j];
                    k++;
                }
                i += 4; 
            }
            else if(left == 3){
                for(j=i ; j<=i+2 ; j++) ans += res[j];
                i += 3; 
            }
            else{
                for(j=i ; j<=i+1 ; j++) ans += res[j];
                i += 2; 
            }
        }
        return ans;
    }
};