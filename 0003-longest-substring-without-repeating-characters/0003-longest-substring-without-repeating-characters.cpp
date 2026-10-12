class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int len = s.length();
        int l = 0, r = 0;
        unordered_map<char, int> m;
        while(r<len){
            // cout<<l<<" "<<r<<endl;
            if(m[s[r]] == 0){
                m[s[r]]++;
                r++;
            }else{
                if(m[s[l]] != 0) m[s[l]]--;
                l++;
            }
            ans = max(ans, r-l);
        }
        return ans;
    }
};