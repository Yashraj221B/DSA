#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> arr = {};
        sort(nums.begin(), nums.end());
        int curr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(i>0 && nums[i-1] == nums[i]) continue;
            for (int j = i+1; j < nums.size(); j++)
            {
                int l = j+1;
                int r = nums.size() - 1;
                while (l<r)
                {
                    curr = nums[i] + nums[j] + nums[l] + nums[r];
                    if (curr == target)
                    {
                        arr.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;r--;
                        while(l < r && nums[l] == nums[l+1]) l++;
                        while(l < r && nums[r] == nums[r-1]) r--;
                    }else if(curr<target){
                        l++;
                    }else{
                        r--;
                    }
                }                
            }
        }
        return arr;
    }
};

int main (int argc, char *argv[]) {
  vector<int> x = {1,2,3,3,4,5,6};
  Solution s = Solution();
  auto res = s.fourSum(x,8);
  for(auto i: res) {
   for(auto j : i) {
      std::cout<<j<<" ";
    }
   std::cout<<'\n';
  }
  return 0;
}
