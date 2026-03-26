#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int temp;
        if(nums.size() == 1) return;
        if(nums.size() == 2){
            temp = nums[0];
            nums[0] = nums[1];
            nums[1] = temp;
            return;
        }
        int idx;
        for(idx = nums.size()-2;idx>=0;idx--){
            if(nums[idx] < nums[idx+1]){
                break;
            }
        }
        if(idx != -1){
            for(int i = nums.size()-1;i>idx;i--){
                if (nums[i] > nums[idx])
                {
                    temp = nums[idx];
                    nums[idx] = nums[i];
                    nums[i] = temp;
                    break;         
                }
            }
        }
        int i = idx+1;
        int j = nums.size()-1;
        while(i<j){
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;    
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    vector<int> t1 = {2,3,1};
    s.nextPermutation(t1);
    for (auto i : t1)
    {
        cout<<i<< "";
    }
    cout<<endl;
}
