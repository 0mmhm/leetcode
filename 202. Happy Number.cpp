class Solution {
public:
    bool isHappy(int n) {
        long long int val, temp, sum = (long long int)n;
        map <long long int, int> mp;
        while(sum > 1){
            temp = sum;
            val = 0;
            while(temp > 0){
                val += (temp%10) * (temp%10);
                temp /= 10;
            }
            
           if(mp[val] > 0) return false;
           mp[val] = 1;
           sum = val;
           
        }
        
        return true;
    }
};