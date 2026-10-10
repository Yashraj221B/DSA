#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> trips;
        sort(nums.begin(), nums.end());

        for (int x = 0; x < nums.size(); x++) {
            if (x > 0 && nums[x] == nums[x - 1]) continue;
            if (nums[x] > 0) break; 
            int l = x + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int sum = nums[x] + nums[l] + nums[r];

                if (sum == 0) {
                    trips.push_back({nums[x], nums[l], nums[r]});
                    
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                }
                else if (sum > 0) r--;
                else l++;
            }
        }
        return trips;
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    vector<int> lst = {0,0,0,0};
    auto x = s.threeSum(lst);
    
    return 0;
}
