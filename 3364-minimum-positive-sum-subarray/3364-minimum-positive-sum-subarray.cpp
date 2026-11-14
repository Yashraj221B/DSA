class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        vector<int> prefix(n,0);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = nums[i]+prefix[i-1];
        }
        for(int i = 0; i < n; i++){
            for(int j = i+l-1; j < i+r && j < n; j++){
                int s = prefix[j] - (i>0?prefix[i-1]:0);
                if(s>0){
                    ans = min(ans, s);
                }
            }
        }
        return (ans==INT_MAX?-1:ans);
    }
};