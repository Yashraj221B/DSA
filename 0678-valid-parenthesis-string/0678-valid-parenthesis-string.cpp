class Solution {
public:
    bool checkValidString(string s) {
        int opn = 0;
        int cls = 0;
        int n = s.length()-1;
        for(int i = 0; i <= n; i++){
            if(s[i] == '(' || s[i] == '*'){
                opn++;
            }else{
                opn--;
            }

            if(s[n-i] == ')' || s[n-i] == '*'){
                cls++;
            }else{
                cls--;
            }

            if(opn < 0 || cls < 0) return false;
        }
        return true;
    }
};