class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<int> ans(tasks.size());
        vector<int> s_status(servers.size(), -1);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> available;
        priority_queue<pair<long long ,int>,vector<pair<long long,int>>, greater<pair<long long,int>>> busy;
        for(int i = 0; i < servers.size(); i++){
            available.push({servers[i],i});
        }
        long long curr_time = 0;
        for (int i=0; i<tasks.size();i++)
        {
            curr_time = max(curr_time, (long long)i);
            if (available.empty()) {
                curr_time = busy.top().first;
            }
            while(!busy.empty() && busy.top().first <= curr_time){
                available.push({servers[busy.top().second],busy.top().second});
                busy.pop();
            }
            ans[i] = available.top().second;
            busy.push({curr_time+tasks[i], available.top().second});
            available.pop();
        }
        return ans;
    }
};