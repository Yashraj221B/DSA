#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for (int i = 0; i < strs[0].length(); i++)
        {
            for (int j = 1; j < strs.size(); j++)
            {
                std::cout<<strs[0][i]<<"|"<<strs[j][i]<<"|"<<prefix<<'\n';
                if(i>strs[j].length() || strs[j][i] != strs[0][i]) return prefix;
            }
            prefix += strs[0][i];
        }
        return prefix;
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    vector<string> lst = {"flower","flow","flight"};
    s.longestCommonPrefix(lst);
    return 0;
}
