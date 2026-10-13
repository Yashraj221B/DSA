class Solution {
private:
public:
    string getString(vector<string> &row, int &len, int &maxWidth){
        if(row.size() == 1) return row[0]+string(maxWidth-len, ' ');
        string ans = row[0];
        int base = (maxWidth-len)/(row.size()-1);
        int extra = (maxWidth-len)%(row.size()-1);
        for(int i = 1; i < row.size(); i++){
            ans+=string(base,' ');
            if(extra > 0){
                ans+=' ';
                extra--;
            }
            ans+=row[i];
        }
        return ans;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> tmp;
        int curr_len = 0;
        for(int i = 0; i < words.size(); i++){
            if(curr_len+words[i].length()+(tmp.size()) <= maxWidth){
                tmp.push_back(words[i]);
                curr_len+=words[i].length();
            }else{
                ans.push_back(getString(tmp, curr_len, maxWidth));
                tmp.clear();
                tmp.push_back(words[i]);
                curr_len = words[i].length();
            }
        }
        ans.push_back([&](){
            string x = tmp[0];
            for(int i = 1; i < tmp.size(); i++){
                x+=" ";
                x+=tmp[i];
            }
            x+=string(maxWidth-x.length(), ' ');
            return x;
        }());
        return ans;
    }
};