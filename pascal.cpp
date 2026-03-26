#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        if(numRows == 2) return {{1},{1,1}};
        vector<vector<int>> rows = {{1},{1,1}};
        vector<int> temp = {};
        for(int i = 2; i < numRows; i++){
            temp.push_back(1);
            for(int j = 1; j < i; j++){
                temp.push_back(rows[i-1][j-1] + rows[i-1][j]);
            }
            temp.push_back(1);
            rows.push_back(temp);
            temp.clear();
        }
        return rows;
    }
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 1) return {1};
        if(rowIndex == 2) return {1,1};
        vector<int> last = {1,1};
        vector<int> temp = {};
        for(int i = 2; i < rowIndex; i++){
            temp.push_back(1);
            for(int j = 1; j < i; j++){
                temp.push_back(last[j-1] + last[j]);
            }
            temp.push_back(1);
            last = temp;
            temp.clear();
        }    
        return last;    
    }
};


int main(int argc, char const *argv[])
{
    Solution s = Solution();
    for(auto x: s.generate(10)){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
