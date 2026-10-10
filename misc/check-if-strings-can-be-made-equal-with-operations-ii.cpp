#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char, int> even;
        unordered_map<char, int> odd;
        for (size_t i = 0; i < s1.length(); i++)
        {
            if(i%2 == 0){
                even[s1[i]]++;
            }else{
                odd[s1[i]]++;
            }
        }
        for(int i = 0; i < s2.length(); i++){
            if(i%2 == 0){
                if(even[s2[i]] == 0) return false;
                else even[s2[i]]--;
            }else{
                if(odd[s2[i]] == 0) return false;
                else odd[s2[i]]--;
            }
        }
    }
};