#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // pos, health, dir, idx
        vector<vector<int>> robots;
        // idx, pos, health, dir
        vector<vector<int>> stk;
        for(int i = 0; i < positions.size(); i++){
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        sort(robots.begin(), robots.end());
        for(int i = 0; i < robots.size(); i++){
            if(stk.empty()) stk.push_back({robots[i][3],robots[i][0],robots[i][1], robots[i][2]});
            else if(robots[i][2] == 'R'){
                stk.push_back({robots[i][3],robots[i][0],robots[i][1], robots[i][2]});
            }else{
                if(stk.back()[3] == 'L') stk.push_back({robots[i][3],robots[i][0],robots[i][1], robots[i][2]});
                else{
                    while(!stk.empty() && stk.back()[3] == 'R'){
                        if(stk.back()[2] == robots[i][1]){
                            robots[i][1] = 0;
                            stk.pop_back();
                            break;
                        }else if(stk.back()[2] > robots[i][1]){
                            stk.back()[2]--;
                            robots[i][1] = 0;
                            break;
                        }else{
                            robots[i][1]--;
                            stk.pop_back();
                        }
                    }
                    if(robots[i][1] > 0){
                        stk.push_back({robots[i][3],robots[i][0],robots[i][1], robots[i][2]});
                    }
                }
            }
        }
        sort(stk.begin(), stk.end());
        vector<int> ans;
        for(auto i: stk){
            ans.push_back(i[2]);
        }
        return ans;
    }
};