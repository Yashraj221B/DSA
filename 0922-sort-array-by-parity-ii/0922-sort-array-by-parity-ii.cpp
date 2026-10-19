class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int o = 1;
        for(int e = 0; e < nums.size(); e+=2){
            if(nums[e]%2 != 0){
                while(nums[o]%2 != 0){
                    o+=2;   
                }
                swap(nums[e], nums[o]);
            }
        }
        return nums;
    }
};