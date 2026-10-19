class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int count = 0;
        int idx = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < target) idx++;
            if(nums[i] == target) count++;
        }
        for(int i = 0; i < count; i++){
            ans.push_back(idx+i);
        }
        return ans;
    }
};