class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size() == 0) return {};
        unordered_map<int, int> m;
        vector<int> tmp(arr.begin(), arr.end());
        sort(tmp.begin(), tmp.end());
        m[tmp[0]] = 1;
        for(int i = 1; i < tmp.size(); i++){
            if(tmp[i-1] == tmp[i]) continue;
            m[tmp[i]] = m[tmp[i-1]]+1;
        }
        for(int i = 0; i < arr.size(); i++){
            arr[i] = m[arr[i]];
        }
        return arr;
    }
};