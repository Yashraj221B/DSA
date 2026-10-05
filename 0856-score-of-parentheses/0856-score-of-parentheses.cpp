class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int nest = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                nest++;
            }else{
                nest--;
                if(s[i-1] == '('){
                    score+=pow(2,nest);
                }
            }
        }
        return score;
    }
};