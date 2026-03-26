#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string compress(string s){
        int i = 0;
        char _ = s[0];
        string enc = "";
        for(char c: s){
            if(_ == c) i++;
            else{
                enc+=(48+i);
                enc+=_;
                _ = c;
                i = 1;
            }
        }
        enc+=(48+i);
        enc+=_;

        return enc;
    }
    string gen(string s, int n, int limit){
        if(n == limit) return s;
        return gen(compress(s),n+1, limit);
    }
    string countAndSay(int n) {
        return gen("1", 1, n);
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    cout<<s.compress("1")<<"\n";
    cout<<s.compress("11")<<"\n";
    cout<<s.compress("21")<<"\n";
    return 0;
}
