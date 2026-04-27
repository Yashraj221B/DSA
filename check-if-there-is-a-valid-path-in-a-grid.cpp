#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> grid;
    vector<vector<int>> visited;
    int m, n;
public:
    bool checkPath(int r, int c, int nr, int nc){
        if(r == m-1 && c == n-1) return true;
        if(nr < 0 || nr == m || nc < 0 || nc == n || grid[nr][nc] == 0) return false;
        if (nc > c && grid[nr][nc] != 1 && grid[nr][nc] != 3 && grid[nr][nc] != 5) return false;
        if (nc < c && grid[nr][nc] != 1 && grid[nr][nc] != 4 && grid[nr][nc] != 6) return false;
        if (nr > r && grid[nr][nc] != 2 && grid[nr][nc] != 5 && grid[nr][nc] != 6) return false;
        if (nr < r && grid[nr][nc] != 2 && grid[nr][nc] != 3 && grid[nr][nc] != 4) return false;
        int pipe = grid[nr][nc];
        grid[nr][nc] = 0;
        switch(pipe){
            case 1:
                if(nc-1 != c) return checkPath(nr,nc,nr,nc-1);
                else return checkPath(nr,nc,nr,nc+1);
                break;
            case 2:
                if(nr-1 != r) return checkPath(nr,nc,nr-1,nc);
                else return checkPath(nr,nc,nr+1,nc);
                break;
            case 3:
                if(nc-1 != c) return checkPath(nr,nc,nr,nc-1);
                else return checkPath(nr,nc,nr+1,nc);
                break;
            case 4:
                if(nc+1 != c) return checkPath(nr,nc,nr,nc+1);
                else return checkPath(nr,nc,nr+1,nc);
                break;
            case 5:
                if(nr-1 != r) return checkPath(nr,nc,nr-1,nc);
                else return checkPath(nr,nc,nr,nc-1);
                break;
            case 6:
                if(nr-1 != r) return checkPath(nr,nc,nr-1,nc);
                else return checkPath(nr,nc,nr,nc+1);
                break;
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        this->grid = grid;
        this->m = grid.size();
        this->n = grid[0].size();
        if (m == 1 && n == 1) return true;
        this->visited = vector(m, vector(n, 0));
        switch(grid[0][0]){
            case 1:
                return checkPath(0,0, 0, 1);
            case 2:
                return checkPath(0,0, 1, 0);
            case 3:
                return checkPath(0,0, 1, 0);
            case 4:
                return checkPath(0,0, 0, 1) || checkPath(0,0,1,0);
            case 5:
                return false;
            case 6:
                return checkPath(0,0, 0, 1);
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    vector<vector<int>> g = {{1,1,2}};
    s.hasValidPath(g);
    return 0;
}
