#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> board;
    string word;
    int m,n;
    bool check(int idx, int row, int col){
        if(idx==word.length()) return true;
        if(row < 0 || row >= m || col < 0 || col >= n || board[row][col] != word[idx]) return false;
        char temp = board[row][col];
        board[row][col] = '#';
        bool result = check(idx+1, row-1, col) || check(idx+1, row+1, col) || check(idx+1, row, col-1) || check(idx+1, row, col+1); 
        board[row][col] = temp;
        return result;
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        this->m = board.size();
        this->n = board[0].size();
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[i].size(); j++)
            {
                if(check(0,i,j)) return true;   
            }   
        }
        return false;
    }
};