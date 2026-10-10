#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;

        for (auto i : strs)
        {
            vector<int> freq(26, 0);
            for (char c : i) freq[c - 'a']++;

            string key = "";
            for (int f : freq) key += to_string(f) + "#";

            group[key].push_back(i);
        }

        vector<vector<string>> res;
        for (auto &p : group) res.push_back(p.second);
        return res;
    }
};