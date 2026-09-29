class Solution {
private:
    vector<vector<char>> grid;
    vector<vector<vector<int>>> memo;
    int m, n;

public:
    bool dfs(int i, int j, int para){
        if(i >= m || j >= n) return false;
        if(memo[i][j][para] != -1) return memo[i][j][para];

        if(grid[i][j] == '(') para++;
        else para--;

        if(para < 0) return false;
        if(i == m-1 && j == n-1) return para == 0;

        return memo[i][j][para - (grid[i][j] == '(' ? 1 : -1)] =
            dfs(i, j+1, para) || dfs(i+1, j, para);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();

        if(grid[0][0] != '(' || grid[m-1][n-1] != ')') return false;
        if((m + n - 1) % 2 != 0) return false;

        this->grid = grid;
        memo.assign(m, vector<vector<int>>(n, vector<int>(m+n, -1)));

        return dfs(0, 0, 0);
    }
};