class Solution {
private:
    string s;
    int len = 0;
    int diff = 0, left = 0, right = 0;
    unordered_set<string> ans;
public:
    void gen(string &part, int idx, int lrem, int rrem, int bal){
        if(bal < 0) return; 
        
        if(idx == len){
            if(part.length() == len-diff && bal == 0){
                ans.insert(part);
            }
            return;
        }

        part.push_back(s[idx]);
        int next_bal = bal + (s[idx] == '(' ? 1 : (s[idx] == ')' ? -1 : 0));
        gen(part, idx+1, lrem, rrem, next_bal);
        part.pop_back();

        if(s[idx] == '(' && lrem > 0){
            gen(part, idx+1, lrem-1, rrem, bal);
        }else if(s[idx] == ')' && rrem > 0){
            gen(part, idx+1, lrem, rrem-1, bal);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        this->s = s;
        len = s.length();
        for(int i = 0; i<len; i++){
            if(s[i] == '('){
                left++;
            }else if(s[i] == ')'){
                if(left > 0) left--;
                else right++;
            }
        }
        diff = left + right;
        string tmp = "";
        gen(tmp, 0, left, right, 0);
        return vector<string>(ans.begin(), ans.end());
    }
};