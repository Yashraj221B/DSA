class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return abs(a) < abs(b);
        });
        int l = 0, r = nums.size()-1;
        long long sum = 0;
        while(l<r){
            sum += 1LL*nums[r]*nums[r];
            sum -= 1LL*nums[l]*nums[l];
            r--;
            l++;
        }
        if(l==r){
            sum += 1LL*nums[r]*nums[r];
        }
        return sum;
    }
};