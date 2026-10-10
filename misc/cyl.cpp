#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> copy;
        for(int i = 0; i < m; i++){
            if(i%2 == 0){
                mat[i].push_back(mat[i][0]);
                mat[i].erase(mat[i].begin());
            }else{
                mat[i].insert(mat[i].begin(), mat[i][n-1]);
                mat[i].pop_back();
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] != copy[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
};