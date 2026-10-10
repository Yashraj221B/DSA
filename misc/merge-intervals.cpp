#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        sort(intervals.begin(),intervals.end());
        int l = 0;
        int maxCurr = intervals[0][1];
        for (int r = 1; r < intervals.size(); r++)
        {
            if(maxCurr >= intervals[r][0]){
                maxCurr = max(intervals[r][1],maxCurr);
            }else{
                merged.push_back({intervals[l][0],maxCurr});
                l = r;
                maxCurr = intervals[r][1];
            }
        }
        merged.push_back({intervals[l][0],maxCurr});
        return merged;
    }
};

int main (int argc, char *argv[]) {
    // vector<vector<int>> x = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> x = {{4,7},{1,4}};
    Solution s = Solution();
    s.merge(x);
    return 0;
}
