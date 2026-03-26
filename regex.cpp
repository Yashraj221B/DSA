#include<bits/stdc++.h>
using namespace std;

class Solution2 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merged;
        int l = 0;
        int r = intervals.size()-1;
        int mid = (l+r)/2;
        // Merge
        if(newInterval[0] <= intervals[l][0]){
            intervals.insert(intervals.begin()+l, newInterval);
        }else if(newInterval[0] >= intervals[r][0]){
            intervals.push_back(newInterval);   
        }else{
            while(l<=r){
                if(intervals[mid][0] == newInterval[0]){
                    intervals.insert(intervals.begin()+mid, newInterval);
                    break;
                }else if(intervals[mid][0] > newInterval[0]){
                    if(l < mid && intervals[mid-1][0] < newInterval[0]){
                        intervals.insert(intervals.begin()+mid,newInterval);
                        break;
                    }else{
                        r = mid-1;
                    }
                }else{
                    if(r > mid && intervals[mid+1][0] > newInterval[0]){
                        intervals.insert(intervals.begin()+mid+1,newInterval);
                        break;
                    }else{
                        l = mid+1;
                    }
                }
                mid = (l+r)/2;
            }
            return intervals;
        }
         
    }
};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int rsub = 0;
        int csub = 0;
        int i,j;
        n--;
        int i = 1;
        vector<int> order;
        while(rsub <= n-rsub && csub <= n-csub){
            for(int j = csub; j <= (n-csub); j++){
                matrix[rsub][j] = i++;
            }
            for(int i = rsub+1; i <= (n-rsub); i++){
                matrix[i][n-csub] = i++;
            }
            if(rsub < n-rsub){
                for(int j = n-csub-1; j >= csub; j--){
                    matrix[n-rsub][j] = i++;
                }
            }
            if(csub < n-csub){
                for(int i = n-rsub-1; i >= rsub+1; i--){
                    matrix[i][csub] = i++;
                }
            }
            rsub++;
            csub++;
        }
        return matrix;
    }
};