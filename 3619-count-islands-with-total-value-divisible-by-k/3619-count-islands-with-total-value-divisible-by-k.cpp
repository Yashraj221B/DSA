class Solution {
private:
    int c=0,m,n;
    long dfs(vector<vector<int>>& grid, int r, int c){
        if(r == m || c == n || r < 0 || c < 0 || grid[r][c] == 0) return 0;
        long long sum = grid[r][c];
        grid[r][c] = 0;
        sum+=dfs(grid, r-1, c);
        sum+=dfs(grid, r+1, c);
        sum+=dfs(grid, r, c-1);
        sum+=dfs(grid, r, c+1);
        return sum;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0){
                    if(dfs(grid,i,j)%k == 0){
                        c++;
                    }
                }
            }
        }
        return c;
    }
};