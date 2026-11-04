class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0; i < n; i++){
            int g = gas[i];
            bool complete = true;
            // cout<<g<<' ';
            for(int j = i+1; j < n+i+1; j++){
                if(g - cost[(j - 1) % n] < 0) {
                    complete = false;
                    i = j-1;
                    break; 
                }
                g = g - cost[(j-1)%n] + gas[j%n];
                // cout<<g<<' ';
            }
            if(complete) return i;
            // cout<<'\n';
        }
        return -1;
    }
};