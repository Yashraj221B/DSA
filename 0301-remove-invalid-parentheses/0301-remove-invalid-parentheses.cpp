class Solution {
private:
    string s;
    int len = 0;
    int diff = 0, left = 0, right = 0;
    unordered_set<string> ans;
public:
    bool isValid(string str){
        int left = 0;
        for(int i = 0; i<str.length();i++){
            if(str[i] == '(') left++;
            else if(str[i] == ')'){
                if(left > 0) left--;
                else return false;
            }
        }
        return left == 0;
    }

    void gen(string &part, int idx, int lrem, int rrem){
        // cout<<part<<'\n';
        if(idx == len){
            if(part.length() == len-diff && isValid(part)){
                ans.insert(part);
            }
            return;
        }
        part.push_back(s[idx]);
        gen(part, idx+1, lrem, rrem);
        part.pop_back();

        if(s[idx] == '(' && lrem>0){
            gen(part, idx+1, lrem-1, rrem);
        }else if(s[idx] == ')' && rrem > 0){
            gen(part, idx+1, lrem, rrem-1);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        if(isValid(s)) return {s};
        this->s = s;
        len = s.length();
        for(int i = 0; i<len; i++){
            if(s[i] == '('){
                left++;
            }else if(s[i] == ')'){
                if(left > 0){
                    left--;
                }else{
                    right++;
                }
            }
        }
        diff=left+right;
        string tmp = "";gen(tmp, 0, left, right);
        return vector<string>(ans.begin(), ans.end());
    }
};