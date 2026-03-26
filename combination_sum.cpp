#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> combinations;
    vector<int> candidates;
    int target;
public:
    void genCombination(vector<int> arr, int sum, int n){
        if(sum == target){
            combinations.push_back(arr);
            return;
        }
        if(n == candidates.size()-1 || sum > target) return;
        arr.push_back(candidates[n]);
        genCombination(arr, sum+candidates[n], n);
        arr.pop_back();

        if(n == candidates.size()-2 || sum > target) return;
        arr.push_back(candidates[n+1]);
        genCombination(arr, sum+candidates[n+1], n+1);
        arr.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->candidates = candidates;
        this->target = target;
        genCombination({},0, 0);
        return combinations;
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    vector<int> candidates = {2,3,6,7};
    s.combinationSum(candidates, 7);
    return 0;
}
