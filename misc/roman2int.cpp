#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string roman = ""; int n;
        n = num/1000;
        roman += string(n,'M');
        num -= n*1000;

        n = num/100;
        if(n < 5){
            if(n == 4) roman += "CD";
            else roman += string(n, 'C');
        }else{
            if(n == 9) roman += "CM";
            else roman += ('D' + string(n-5,'C'));
        }
        num-=n*100;
        
        n = num/10;
        if(n < 5){
            if(n == 4) roman += "XL";
            else roman += string(n, 'X');
        }else{
            if(n == 9) roman += "XC";
            else roman += ('L' + string(n-5,'X'));
        }
        num-=n*10;
        n = num/1;
        if(n < 5){
            if(n == 4) roman += "IV";
            else roman += string(n, 'I');
        }else{
            if(n == 9) roman += "IX";
            else roman += ('V' + string(n-5,'I'));
        }

        return roman;
    }
};

int main(int argc, char const *argv[])
{
    Solution x = Solution();
    x.intToRoman(58);
    return 0;
}

