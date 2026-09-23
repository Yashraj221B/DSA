class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int mid = (l+r)/2;

        while(l<=r){
            // cout<<l<<" "<<mid<<" "<<r<<"\n";
            if(nums[mid] == target) return mid;
            else if(nums[l] <= nums[mid]){
                if(target < nums[mid] && target >= nums[l]){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
            else{
                if(target > nums[mid] && target <= nums[r]){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
            mid = (l+r)/2;
        }
        return -1;
    }
};