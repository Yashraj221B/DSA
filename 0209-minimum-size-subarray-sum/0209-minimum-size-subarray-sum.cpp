class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int l = 0, r = 0, s = 0;
        while(l < n && r < n){
            s+=nums[r++];
            while(s >= target){
                ans = min(ans, r-l);
                s-=nums[l++];
            }
        }
        return (ans==INT_MAX?0:ans);
    }
};