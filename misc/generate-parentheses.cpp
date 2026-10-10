#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<string> patterns;
public:
    void generate(string str, int op, int cl){
        if(op == 0 && cl == 0){
            patterns.push_back(str);
            return;
        }
        if(op!=0) generate(str+'(', op-1,cl);
        if(cl!=0 && op<cl) generate(str+')', op,cl-1);
    }
    vector<string> generateParenthesis(int n) {
        generate("(",n-1,n);
        return patterns;
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    s.generateParenthesis(3);
    return 0;
}
