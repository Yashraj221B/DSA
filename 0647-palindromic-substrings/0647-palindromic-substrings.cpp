class Solution {
public:
    int countSubstrings(string s) {
        int c = 0;
        int l, r, n = s.length();
        for(int i = 0; i < n; i++){
            l = i;
            r = i;
            while(l>=0 && r < n && s[l] == s[r]){
                // cout<<s.substr(l, r-l+1)<<'\n';
                c++;
                l--;
                r++;
            }
            l = i;
            r = i+1;
            while(l>=0 && r < n && s[l] == s[r]){
                // cout<<s.substr(l, r-l+1)<<'\n';
                c++;
                l--;
                r++;
            }
        }
        return c;
    }
};