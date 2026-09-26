class Solution {
public:
    int reverseDegree(string s) {
        int deg = 0;
        for(int i = 0; i < s.length(); i++){
            cout<<s[i];
            deg += (i+1)*(26-s[i]+'a');
        }
        return deg;
    }
};