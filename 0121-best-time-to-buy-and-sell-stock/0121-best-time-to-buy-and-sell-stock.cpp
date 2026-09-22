class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int diff = 0;
        int m = prices[0];
        for(int i = 0; i < prices.size(); i++){
            diff = max(diff, prices[i] - m);
            m = min(m, prices[i]);
        }
        return diff;
    }
};