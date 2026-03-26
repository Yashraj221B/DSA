#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

class Solution {
    long long m = 0, n = 0;
    long long s1_sum = 0, s2_sum = 0, tot_sum = 0;
    unordered_map<int, int> s1_map, s2_map, tot_map;
public:
    bool checkHorizontal(vector<vector<int>> &grid){
        s1_sum = 0; s2_sum = tot_sum;
        s1_map = {}; s2_map = tot_map;
        for (size_t i = 0; i < m-1; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                s1_sum+=grid[i][j];   
                s2_sum-=grid[i][j];
                s1_map[grid[i][j]]++;
                s2_map[grid[i][j]]--;
            }
            long long diff = abs(s1_sum - s2_sum);
            if(s1_sum == s2_sum){
                return true;
            }else if(s1_sum > s2_sum){
                if(i == 0){
                    if(grid[0][0] == diff || grid[0][n-1] == diff) return true;
                }
                else if(s1_map[diff] > 0){
                    return true;
                }
            }else {
                if(i == m - 2){
                    if(grid[m-1][0] == diff || grid[m-1][n-1] == diff) return true;
                }
                else if(s2_map[diff] > 0){
                    return true;
                }
            }
        }
        return false;
    }
    bool checkVertical(vector<vector<int>> &grid){
        s1_sum = 0; s2_sum = tot_sum;
        s1_map = {}; s2_map = tot_map;
        for (size_t j = 0; j < n-1; j++)
        {
            for (size_t i = 0; i < m; i++)
            {
                s1_sum+=grid[i][j];   
                s2_sum-=grid[i][j];
                s1_map[grid[i][j]]++;
                s2_map[grid[i][j]]--;
            }
            long long diff = abs(s1_sum - s2_sum);
            if(s1_sum == s2_sum){
                return true;
            }else if(s1_sum > s2_sum){
                if(j == 0){
                    if(grid[0][0] == diff || grid[m-1][0] == diff) return true;
                }
                else if(s1_map[diff] > 0){
                    return true;
                }
            }else {
                if(j == n - 2){
                    if(grid[0][n-1] == diff || grid[m-1][n-1] == diff) return true;
                }
                else if(s2_map[diff] > 0){
                    return true;
                }
            }
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        tot_sum = 0;
        tot_map.clear();
        if(n == 1 && m == 1){
            return false;
        }else if(m == 1 && n == 2){
            return grid[0][0] == grid[0][1];
        }else if(n == 1 && m == 2){
            return grid[0][0] == grid[1][0];
        }
        for(size_t i = 0; i < m; i++){
            for (size_t j = 0; j < n; j++)
            {
                tot_sum+=grid[i][j];
                tot_map[grid[i][j]]++;
            }
        }
        s1_sum = 0;
        s2_sum = tot_sum;
        if(m == 1){
            for (size_t j = 0; j < n-1; j++)
            {
                s1_sum+=grid[0][j];
                s2_sum-=grid[0][j];
                long long diff = abs(s1_sum-s2_sum);
                if(s1_sum == s2_sum) return true;
                else if(s1_sum > s2_sum && (diff == grid[0][0] || diff == grid[0][j])) return true;
                else if(s2_sum > s1_sum && (diff == grid[0][j+1] || diff == grid[0][n-1])) return true;
            }
            return false;
        }else if(n == 1){
            for (size_t i = 0; i < m-1; i++)
            {
                s1_sum+=grid[i][0];
                s2_sum-=grid[i][0];
                long long diff = abs(s1_sum-s2_sum);
                if(s1_sum == s2_sum) return true;
                else if(s1_sum > s2_sum && (diff == grid[0][0] || diff == grid[i][0])) return true;
                else if(s2_sum > s1_sum && (diff == grid[i+1][0] || diff == grid[m-1][0])) return true;
            }
            return false;
        }
        bool soln = false;
        soln = checkHorizontal(grid);
        if(!soln)
            soln = checkVertical(grid);
        return soln;
    }
};
