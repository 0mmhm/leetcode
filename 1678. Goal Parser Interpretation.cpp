class Solution {
public:
    string interpret(string command) {
        int len = command.length();
        string res = "";
        for(int i=0 ; i<len ; i++ ){
            if( command[i] == 'G' ) res += 'G';
            else{
                if(command[i+1] == 'a'){ 
                    res += "al";  
                    i += 3;
                }
                else{
                    res += 'o';
                    i++;
                }
            }
        }
        return res;
    }
};