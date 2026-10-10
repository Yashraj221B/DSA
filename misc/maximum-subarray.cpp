#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSum(vector<int> arr, int l, int r){
        int sum = 0;
        while(l<=r){
            sum += arr[l];
            sum += arr[r];
            l++;
            r--;
        }
        return sum;
    }

    int maxSubArray(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int sum = nums[0], temp;
        while(l<r){
            temp = getSum(nums, l, r);
            if(temp > sum) sum = temp;
            l < r ? l++ : r--;
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s = Solution();
    maxSubArray(arr);
    return 0;
}
