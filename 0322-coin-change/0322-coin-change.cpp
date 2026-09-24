class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> tot(amount+1, amount+1);
        tot[0] = 0;
        for(int i = 0; i <= amount; i++){
            for(int c: coins){
                if(c <= i) tot[i] = min(tot[i], tot[i-c]+1);
            }
        }
        // for(int w: tot){
        //     cout<<w<<" ";
        // }
        return tot[amount] == amount+1?-1:tot[amount];
    }
};