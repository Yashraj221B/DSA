#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int amt = 0;
        int l = 0;
        int r = height.size();
        while (l < r)
        {
            cout<<l<<"|"<<r;
            amt = max(amt, min(height[l], height[r])*(r-l));
            cout<<"|"<<amt<<'\n';
            if(height[l] < height[r]) l++;
            else r--;
        }
        return amt;
    }
};

int main(){
    vector<int> x = {1,8,6,2,5,4,8,3,7};
    Solution s;
    cout<<s.maxArea(x)<<endl;
}