class Solution {
public:
    int getOnes(int n){
        int ones = 0;
        while(n != 0){
            ones += n&1;
            n>>=1;
        }
        return ones;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(getOnes(i) == k){
                sum += nums[i];
            }
        }
        return sum;
    }
};