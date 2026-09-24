class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        int tmp = 0;
        while(l<r){
            tmp = numbers[l] + numbers[r];
            if(tmp == target) return {l+1,r+1};
            else if(tmp < target) l++;
            else r--;
        }
        return {-1,-1};
    }
};