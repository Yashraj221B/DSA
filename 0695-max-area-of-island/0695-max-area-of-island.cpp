class Solution {
private:
    int area=0,m,n;
    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r == m || c == n || r < 0 || c < 0 || grid[r][c] == 0) return 0;
        int sum = grid[r][c];
        grid[r][c] = 0;
        sum+=dfs(grid, r-1, c);
        sum+=dfs(grid, r+1, c);
        sum+=dfs(grid, r, c-1);
        sum+=dfs(grid, r, c+1);
        return sum;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0){
                    area = max(area, dfs(grid,i,j));
                }
            }
        }
        return area;
    }
};