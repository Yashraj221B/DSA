class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> kmap;
        for(vector<string> i: knowledge){
            kmap[i[0]] = i[1];
        }
        string key = "";
        string ans = "";
        for(int i = 0; i < s.length();i++){
            if(s[i] == '('){
                i++;
                while(s[i] != ')'){
                    key+=s[i];
                    i++;
                }
                ans+= kmap.count(key) != 0 ? kmap[key] : "?";
                // cout<<key<<" "<<kmap[key]<<'\n';
                key="";
            }else{ 
                ans +=s[i];
            }
        }
        return ans;
    }
};