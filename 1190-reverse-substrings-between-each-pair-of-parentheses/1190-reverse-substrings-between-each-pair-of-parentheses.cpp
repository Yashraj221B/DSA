class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string ans;
        for(int i = 0; i < s.length(); i++){
            // cout<<s<<"\n";
            if(s[i] == '('){
                st.push(i);
                // cout<<"PUSH "<<i<<endl;
            }else if(s[i] == ')'){
                int pos = st.top();
                // cout<<"REV "<<pos<<" "<<i<<endl;
                reverse(s.begin()+pos, s.begin()+i);
                st.pop();
            }
        }
        for(auto c: s){
            if(c == '(' || c == ')') continue;
            ans+=c;
        }
        return ans;
    }
};