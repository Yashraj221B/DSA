class Solution {
public:
    bool checkOpp(char c, char top){
        switch (c)
        {
        case ')': return top == '(';
        case '}': return top == '{';
        case ']': return top == '[';
        default: return false;
        }
    }

    bool isValid(string s) {
        vector<char> stk;
        for (char c : s)
        {
            if(c == '(' || c == '{' || c == '['){
                stk.push_back(c);
            }
            else{
                if(stk.empty() || !checkOpp(c, stk.back()))
                    return false;
                stk.pop_back();
            }
        }
        return stk.empty();
    }
};