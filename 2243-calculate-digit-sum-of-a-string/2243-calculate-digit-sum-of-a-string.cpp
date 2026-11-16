class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length() > k){
            int i = 0;
            string tmp = "";
            while(i < s.length()){
                int sum = 0;
                for(int j = 0; j < k && i+j < s.length(); j++){
                    sum += (s[i+j]-'0');
                    // cout<<i+j<<' ';
                }
                i+=k;
                // cout<<'\n';
                tmp+=to_string(sum);
            }
            s = tmp;
        }
        return s;
    }
};