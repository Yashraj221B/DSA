#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row;
        unordered_set<char> col;
        unordered_set<char> block;
        for(int i = 0; i < 9;i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(row.count(board[i][j]) != 0) 
                    return false;
                    else row.insert(board[i][j]);
                }
                if(board[j][i] != '.'){
                    if(col.count(board[j][i]) != 0)
                        return false;
                    else col.insert(board[j][i]);
                }
            }
            row.clear();
            col.clear();
        }
        for(int r = 0; r < 3; r++){
            for(int c = 0; c < 3; c++){
                
                unordered_set<char> block;

                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){

                        char val = board[r*3 + i][c*3 + j];

                        if(val != '.'){
                            if(block.count(val))
                                return false;
                            block.insert(val);
                        }
                    }
                }
            }
        }
        
        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'}
                                ,{'6','.','.','1','9','5','.','.','.'}
                                ,{'.','9','8','.','.','.','.','6','.'}
                                ,{'8','.','.','.','6','.','.','.','3'}
                                ,{'4','.','.','8','.','3','.','.','1'}
                                ,{'7','.','.','.','2','.','.','.','6'}
                                ,{'.','6','.','.','.','.','2','8','.'}
                                ,{'.','.','.','4','1','9','.','.','5'}
                                ,{'.','.','.','.','8','.','.','7','9'}};
    Solution s = Solution();
    cout<<s.isValidSudoku(board)<<endl;
    // vector<int> arr = {12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    // cout<<s.search(arr,0)<<'|'<<0<<'\n';
    // arr = {11, 12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // cout<<s.search(arr,0)<<'|'<<1<<'\n';
    // arr = {10, 11, 12, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // cout<<s.search(arr,0)<<'|'<<2<<'\n';
    // arr = {9, 10, 11, 12, 1, 2, 3, 4, 5, 6, 7, 8};
    // cout<<s.search(arr,0)<<'|'<<3<<'\n';
    // arr = {8, 9, 10, 11, 12, 1, 2, 3, 4, 5, 6, 7};
    // cout<<s.search(arr,0)<<'|'<<4<<'\n';
    // arr = {7, 8, 9, 10, 11, 12, 1, 2, 3, 4, 5, 6};
    // cout<<s.search(arr,0)<<'|'<<5<<'\n';
    // arr = {6, 7, 8, 9, 10, 11, 12, 1, 2, 3, 4, 5};
    // cout<<s.search(arr,0)<<'|'<<6<<'\n';
    // arr = {5, 6, 7, 8, 9, 10, 11, 12, 1, 2, 3, 4};
    // cout<<s.search(arr,0)<<'|'<<7<<'\n';
    // arr = {4, 5, 6, 7, 8, 9, 10, 11, 12, 1, 2, 3};
    // cout<<s.search(arr,0)<<'|'<<8<<'\n';
    // arr = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 1, 2};
    // cout<<s.search(arr,0)<<'|'<<9<<'\n';
    // arr = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 1};
    // cout<<s.search(arr,0)<<'|'<<10<<'\n';
    // arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    // cout<<s.search(arr,0)<<'|'<<11<<'\n';
    return 0;
}
