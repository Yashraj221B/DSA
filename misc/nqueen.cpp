#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<string>> soln;
    int size;
public:
    bool isValid(vector<string> &board, int r, int c){
        // Column check
        for(int i = 0; i < r; i++){
            if(board[i][c] == 'Q') return false;
        }
        // Diagonal check
        for(int i = 1; (r-i) >= 0 && (c-i) >= 0;i++){
            if(board[r-i][c-i] == 'Q') return false;
        }
        // Another Diagonal check
        for(int i = 1; (r-i) >= 0 && (c+i) < size;i++){
            if(board[r-i][c+i] == 'Q') return false;
        }
        return true;
    }
    void solve(vector<string> &board, int q, int r){
        if(q <= 0){
            soln.push_back(board);
            return;
        }
        if(r == size) return;
        for(int c = 0; c < size; c++){
            if(isValid(board, r, c)){
                board[r][c] = 'Q';
                solve(board, q-1, r+1);
                board[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        this->size = n;
        vector<string> board(n,string(n,'.'));
        solve(board, n, 0);
        return soln;
    }
};

class Solution {
private:
    int solutions = 0;
    int size;
public:
    bool isValid(vector<string> &board, int r, int c){
        // Column check
        for(int i = 0; i < r; i++){
            if(board[i][c] == 'Q') return false;
        }
        // Diagonal check
        for(int i = 1; (r-i) >= 0 && (c-i) >= 0;i++){
            if(board[r-i][c-i] == 'Q') return false;
        }
        // Another Diagonal check
        for(int i = 1; (r-i) >= 0 && (c+i) < size;i++){
            if(board[r-i][c+i] == 'Q') return false;
        }
        return true;
    }
    void solve(vector<string> &board, int q, int r){
        if(q <= 0){
            solutions += 1;
            return;
        }
        if(r == size) return;
        for(int c = 0; c < size; c++){
            if(isValid(board, r, c)){
                board[r][c] = 'Q';
                solve(board, q-1, r+1);
                board[r][c] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        this->size = n;
        vector<string> board(n,string(n,'.'));
        solve(board, n, 0);
        return solutions;
    }
};