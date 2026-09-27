class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0, curr = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
            curr += i * nums[i];
        }

        long long m = curr;

        for(int i = n-1; i > 0; i--){
            curr = curr + sum - n * nums[i];
            m = max(m, curr);
        }

        return m;
    }
};