class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length() > k){
            string tmp = "";
            for(int i = 0; i < s.length(); i+=k){
                int sum = 0;
                for(int j = 0; j < k && i+j < s.length(); j++){
                    sum += s[i+j]-'0';
                }
                tmp+=to_string(sum);
            }
            s = tmp;
        }
        return s;
    }
};