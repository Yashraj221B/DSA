class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0, even = 1, tot = 0, pre = 0;
        for(int i: arr){
            pre+=i;
            if((pre&1) == 0){
                tot=(tot+odd)%1000000007;
                even++;
            }else{
                tot=(tot+even)%1000000007;
                odd++;
            }
        }
        return tot;
    }
};