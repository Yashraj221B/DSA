#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        while (i<=haystack.length()-needle.length())
        {
            cout<<i<<"|"<<i+needle.length();
            cout<<haystack.substr(i,needle.length())<<endl;
            if(haystack.substr(i,needle.length()).compare(needle) == 0) return i;
            i++;
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    s.strStr("a","a");
    return 0;
}
