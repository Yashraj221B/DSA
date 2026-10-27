class Solution {
private:
    int m, n, ans;
    bool canrot(vector<vector<int>>& grid, int r, int c){
        bool a = false;
        if(r-1 >= 0){
            a|=(grid[r-1][c]==2);
        }
        if(r+1 < m && !a){
            a|=(grid[r+1][c]==2);
        }
        if(c-1 >= 0 && !a){
            a|=(grid[r][c-1]==2);
        }
        if(c+1 < n && !a){
            a|=(grid[r][c+1]==2);
        }
        return a;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size(), ans = 0;
        bool changed;
        stack<pair<int, int>> update;
        while(true){
            changed = false;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] == 1 && canrot(grid, i, j)){
                        update.push({i,j});
                        changed=true;
                    }
                }
            }
            if(changed == false) break;
            ans++;
            while(!update.empty()){
                pair<int, int> u = update.top();
                update.pop();
                grid[u.first][u.second] = 2;
            }
        };
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1) return -1;
        return ans;
    }
};