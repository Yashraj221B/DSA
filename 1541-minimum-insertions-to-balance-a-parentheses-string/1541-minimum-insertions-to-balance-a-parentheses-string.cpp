class Solution {
public:
    int minInsertions(string s) {
        int bal = 0;
        int mov = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                bal+=1;
            }else{
                if(i+1 < s.length() && s[i+1] == ')'){
                    if(bal == 0){
                        bal++;
                        mov++;
                    }
                    i++;
                }else{
                    if(bal == 0){
                        mov+=2;
                        bal++;
                    }else{
                        mov++;
                    }
                }
                bal--;
            }
        }
        mov += bal*2;
        return mov;
    }
};