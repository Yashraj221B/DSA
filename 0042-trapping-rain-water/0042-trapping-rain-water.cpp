class Solution {
public:
    int trap(vector<int>& height) {
        int count = 0;
        int l = 1; int r = height.size()-2;
        int lmax = height[0], rmax = height[height.size()-1];
        while(l <= r){
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            if(rmax > lmax){
                count += lmax - height[l++];
            }else{
                count += rmax - height[r--];
            }
        }
        return count;
    }
};