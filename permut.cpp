#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permutations;

    void backtrack(vector<int>& arr, vector<int>& nums, vector<bool>& visited){
        if(arr.size() == nums.size()){
            permutations.push_back(arr);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(visited[i]) continue;
            visited[i] = true;
            arr.push_back(nums[i]);
            backtrack(arr, nums, visited);
            arr.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> arr;
        vector<bool> visited(nums.size(), false);
        backtrack(arr, nums, visited);
        return permutations;
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    int n;
    cout<<"Enter Number: ";
    cin>>n;
    vector<int> arr;
    for(int i = 1; i <= n; i++){
        arr.push_back(i);
    }
    auto prts = s.permute(arr);
    for(int i = 0; i < prts.size(); i++){
        cout<<i+1<<"] ";
        for(int j = 0; j < n; j++){
            cout<<prts[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
