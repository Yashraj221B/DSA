
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<int> ans(queries.size()), cnt(n);
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {return a[1] < b[1];});
        vector<int> idx(queries.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {return queries[a] < queries[b];});

        int left = 0, right = 0, active = 0;
        for(int i = 0; i < queries.size(); i++) {
            int q = queries[idx[i]];
            while(right < logs.size() && logs[right][1] <= q) {
                int id = logs[right][0];
                if(cnt[id-1] == 0)
                    active++;
                cnt[id-1]++;
                right++;
            }
            while(left < right && logs[left][1] < q - x) {
                int id = logs[left][0];
                cnt[id-1]--;
                if(cnt[id-1] == 0)
                    active--;
                left++;
            }
            ans[idx[i]] = n - active;
        }
        return ans;
    }
};
