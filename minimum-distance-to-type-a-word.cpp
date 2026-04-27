#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> getPos(char c){
        c-='A';
        int x = c/6;
        int y = c%6;
        return {x,y};
    }
public:
    int minimumDistance(string word) {
        vector<vector<vector<int>>> dp(26, vector<vector<int>>(26, vector<int>(0)));
        char c = 'A';
        while(c<='Z'){
            auto pos = getPos(c);
            cout<<pos[0]<<" "<<pos[1];
        }
        return 0;
    }
};