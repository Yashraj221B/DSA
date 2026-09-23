class Solution {
public:
    int getSum(int a, int b) {
        int c = 0;
        int ans = 0;
        int b1, b2;
        int n = 1;
        for(int i = 0; i < 32; i++){
            b1 = a&1;
            b2 = b&1;
            a>>=1;
            b>>=1;
            if(b1 == 0 && b2 == 0){
                if(c == 1){
                    ans|=n;
                    c = 0;
                }
            }
            else if((b1 == 0 && b2 == 1) || (b1 == 1 && b2 == 0)){
                if(c == 0){
                    ans|=n;
                }
            }else{
                if(c == 1){
                    ans|=n;
                }
                c = 1;
            }
            n<<=1;
        }
        if(c == 1){
            ans|=n;
        }
        return ans;
    }
};