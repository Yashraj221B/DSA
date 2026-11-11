class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int i = 2;
        int ans = stoi(to_string(nums[0])+to_string(nums[1]));
        while(i<nums.size()){
            ans = min(ans, stoi(to_string(nums[i])+to_string(nums[i+1])));
            i+=2;
        }
        return ans;
    }
};