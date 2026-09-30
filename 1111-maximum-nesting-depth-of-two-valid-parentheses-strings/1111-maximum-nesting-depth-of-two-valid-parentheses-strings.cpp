class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans(seq.length());
        int d = 0;
        for(int i = 0; i < seq.length(); i++){
            if(seq[i] == '('){
                ans[i] = d%2;
                d++;
            }else{
                ans[i] = d%2 == 0?1:0;
                d--;
            }
        }
        return ans;
    }
};