class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = nums.size()-1, mid = (l+r)/2;
        while(l<r){
            if(mid+1 < n && nums[mid+1] < nums[mid]){
                return nums[mid+1];
            }else if(mid-1 >= 0 && nums[mid-1] > nums[mid]){
                return nums[mid];
            }else if(nums[r] > nums[mid]){
                r = mid-1;
            }else if(nums[r] < nums[mid]){
                l = mid+1;
            }else{
                r--;
            }
            mid = (l+r)/2;
        }
        return nums[l];
    }
};