class Solution {
private:
    int m, n, count;
    void dfs(vector<vector<char>>& board, int r, int c){
        if(r < 0 || c < 0 || r == m || c == n || board[r][c] != 'X') return;
        board[r][c] = '.';
        dfs(board, r-1, c);
        dfs(board, r+1, c);
        dfs(board, r, c-1);
        dfs(board, r, c+1);
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(board[r][c] == 'X'){
                    count++;
                    dfs(board,r,c);
                }
            }
        }
        return count;
    }
};