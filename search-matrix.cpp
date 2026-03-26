#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int8_t m = matrix.size();
        int8_t n = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
        for(int8_t i = 0; i < m; i++){
            if(matrix[i][n-1] >= target){
                m = i;
                break;
            }
        }
        int8_t a = 0, b = n-1, mid = (a+b)/2;
        while(a <= b){
            if(matrix[m][mid] == target) return true;
            if(matrix[m][mid] < target) a = mid + 1;
            else b = mid-1;
            mid = (a+b)/2;
        }
        return false;
    }
};