class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int m = intervals[0][1];
        int s = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= m){
                m = max(m, intervals[i][1]);
            }else{
                ans.push_back({intervals[s][0],m});
                s = i;
                m = intervals[i][1];
            }
        }
        ans.push_back({intervals[s][0], m});
        return ans;
    }
};