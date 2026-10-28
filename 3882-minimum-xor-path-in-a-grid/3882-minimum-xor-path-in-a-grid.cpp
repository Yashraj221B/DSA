#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));
        dp[0][0][grid[0][0]] = 1;
        for(int i = 1; i < m; i++){
            for(int x = 0; x < 1024; x++) {
                if (dp[i-1][0][x]) {
                    dp[i][0][x ^ grid[i][0]] = 1;
                }
            }
        }
        for(int i = 1; i < n; i++){
            for(int x = 0; x < 1024; x++) {
                if (dp[0][i-1][x]) {
                    dp[0][i][x ^ grid[0][i]] = 1;
                }
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                for(int x = 0; x < 1024; x++) {
                    if (dp[i-1][j][x] || dp[i][j-1][x]) {
                        dp[i][j][x ^ grid[i][j]] = 1;
                    }
                }
            }
        }
        for(int x = 0; x < 1024; x++) {
            if (dp[m-1][n-1][x]) {
                return x;
            }
        }
        return 0;
    }
};