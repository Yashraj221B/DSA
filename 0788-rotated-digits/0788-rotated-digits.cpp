class Solution {
public:
    int getRot(int n){
        int rot = 0;
        int place = 1;
        while(n != 0){
            switch(n%10){
                case 0:
                case 1:
                case 8:
                    rot += (n%10) * place;
                    break;
                case 2:
                    rot += 5 * place;
                    break;
                case 5:
                    rot += 2 * place;
                    break;
                case 6:
                    rot += 9 * place;
                    break;
                case 9:
                    rot += 6 * place;
                    break;
                default:
                    return -1;
            }
            n/=10;
            place*=10;
        }
        return rot;
    }
    int rotatedDigits(int n) {
        int good = 0;
        for(int i = 1; i <= n; i++){
            int r = getRot(i);
            if(r != -1 && r != i){
                cout<<i<<" "<<r;
                good++;
            }
        }
        return good;
    }
};