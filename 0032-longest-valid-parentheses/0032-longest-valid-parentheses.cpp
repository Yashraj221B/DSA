class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> idx;
        idx.push(-1);
        int valid = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if(s[i] == '('){
                idx.push(i);
            }else{
                idx.pop();

                if(idx.empty()){
                    idx.push(i);
                }else{
                    valid = max(valid, i - idx.top());
                }
            }
        }

        return valid;
    }
};