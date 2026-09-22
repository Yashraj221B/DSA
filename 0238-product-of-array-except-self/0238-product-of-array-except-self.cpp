class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int pref[n];
        int suff[n];
        pref[0] = 1;
        suff[n-1] = 1;
        for(int i = 1; i < n; i++){
            cout<<n;
            pref[i] = pref[i-1] * nums[i-1];
            suff[n-1-i] = suff[n-i] * nums[n-i];
        }
        for(int i = 0; i < n;i++){
            nums[i] = pref[i]*suff[i];
        }
        return nums;
    }
};