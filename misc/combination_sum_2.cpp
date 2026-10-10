#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> combinations;
    vector<int> candidates;
    int target;
public:
    void genCombination(vector<int>& arr, int sum, int n){
        if(sum == target){
            combinations.push_back(arr);
            for (auto &&i : arr)
            {
                cout<<i<<" ";
            }
            cout<<"\n";
            return;
        }
        if(n == candidates.size() || sum > target) return;
        
        arr.push_back(candidates[n]);
        genCombination(arr, sum+candidates[n], n+1);
        arr.pop_back();

        while(n+1 < candidates.size() && candidates[n] == candidates[n+1]) n++;

        genCombination(arr, sum, n+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {  
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        this->target = target;
        vector<int> arr;
        genCombination(arr, 0, 0);
        return combinations;
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    vector<int> candidates = {10,1,2,7,6,1,5};
    s.combinationSum2(candidates, 8);
    return 0;
}
