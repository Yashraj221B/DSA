#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum = nums[0] + nums[1] + nums[2];
        int l, r;
        sort(nums.begin(), nums.end());

        for(int x = 0; x < nums.size(); x++){
            l = x+1;
            r = nums.size() - 1;
            while(l < r){
                if(abs(sum - target) > abs(nums[x]+nums[l]+nums[r] - target)){
                    sum = nums[x] + nums[l] + nums[r];
                }else if(target > nums[x] + nums[l] + nums[r]){
                    l++;
                }else{
                    r--;
                }
            }
            if(sum == target) return sum;
        }

        return sum;
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    vector<int> lst = {4,0,5,-5,3,3,0,-4,-5};
    s.threeSumClosest(lst, -2);
    return 0;
}
