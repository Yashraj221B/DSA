class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size()-1;
        int m = arr[n];
        arr[n] = -1;
        int tmp;
        for(int i = n-1; i >= 0; i--){
            tmp = arr[i];
            arr[i] = m;
            m = max(m, tmp);
        }
        return arr;
    }
};