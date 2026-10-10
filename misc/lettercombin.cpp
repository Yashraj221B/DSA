#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string num2letters(char num){
        switch (num)
        {
        case '2':
            return "abc";
            break;
        
        case '3':
            return "def";
            break;
        
        case '4':
            return "ghi";
            break;
        
        case '5':
            return "jkl";
            break;
        
        case '6':
            return "mno";
            break;
        
        case '7':
            return "pqrs";
            break;
        
        case '8':
            return "tuv";
            break;
        
        case '9':
            return "wxyz";
            break;
        
        default:
            return 0;
            break;
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> combi = {};
        auto btrack = [&](auto&& self, int i, string curr){
            if(curr.length() == digits.length()){
                combi.push_back(curr);
                return;
            }
            for (char c : num2letters(digits[i]))
                self(self, i+1, curr+c);
        };
        btrack(btrack,0,"");
        return combi;
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    auto x = s.letterCombinations("23");
    for (auto &&i : x)
    {
        cout<<i<<" ";
    }
    
    return 0;
}
