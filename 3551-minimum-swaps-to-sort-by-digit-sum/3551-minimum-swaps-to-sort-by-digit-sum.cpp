class Solution {
public:
    int getSum(int x){
        int s = 0;
        while(x!=0){
            s+=x%10;
            x/=10;
        }
        return s;
    }
    int minSwaps(vector<int>& nums) {
        int swaps = 0;
        // idx - digitsum
        vector<pair<int, int>> tmp;
        for(int i = 0; i < nums.size(); i++){
            tmp.push_back({i,getSum(nums[i])});
        }
        sort(tmp.begin(), tmp.end(), [&](pair<int,int> a, pair<int,int> b){
            if(a.second == b.second)
                return nums[a.first] < nums[b.first];
            else
                return a.second < b.second;
        });
        // for(int i = 0; i < tmp.size(); i++){
        //     cout<<nums[tmp[i].first]<<' '<<tmp[i].first<<' '<<tmp[i].second<<'\n';
        // }
        vector<bool> visited(nums.size(), false);
        for(int i = 0; i < nums.size(); i++){
            if(visited[i] || tmp[i].first == i) continue;
            int j = i;
            int cyl = 0;
            while(!visited[j]){
                visited[j] = true;
                j = tmp[j].first;
                cyl++;
            }
            if(cyl > 0) {
                swaps += (cyl - 1);
            }
        }
        return swaps;
    }
};