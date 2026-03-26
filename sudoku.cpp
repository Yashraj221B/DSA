#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>>* board;
    vector<char> digits = {'1','2','3','4','5','6','7','8','9'};

    bool isValid(char digit, int r, int c){
        for(int i=0;i<9;i++){
            if((*board)[r][i]==digit) return false;
            if((*board)[i][c]==digit) return false;
        }

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if((*board)[(r/3)*3+i][(c/3)*3+j]==digit)
                    return false;
            }
        }

        return true;
    }

    bool solve(int r,int c){
        if(r==9) return true;
        if(c==9) return solve(r+1,0);

        if((*board)[r][c] != '.')
            return solve(r,c+1);

        for(char d:digits){
            if(isValid(d,r,c)){
                (*board)[r][c]=d;

                if(solve(r,c+1))
                    return true;

                (*board)[r][c]='.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board){
        this->board=&board;
        solve(0,0);
    }
};