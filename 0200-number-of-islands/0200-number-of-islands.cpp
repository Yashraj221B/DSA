class Solution {
private:
    int c=0,m,n;
    void dfs(vector<vector<char>>& grid, int r, int c){
        if(r == m || c == n || r < 0 || c < 0 || grid[r][c] != '1') return;
        grid[r][c] = '0';
        dfs(grid, r-1, c);
        dfs(grid, r+1, c);
        dfs(grid, r, c-1);
        dfs(grid, r, c+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    c++;
                    dfs(grid,i,j);
                }
            }
        }
        return c;
    }
};