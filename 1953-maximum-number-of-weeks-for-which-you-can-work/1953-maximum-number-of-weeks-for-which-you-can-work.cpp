class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long tot = 0;
        long long mv = 0;
        
        for (int m : milestones) {
            tot += m;
            mv = max(mv, (long long)m);
        }
        
        long long rest = tot - mv;
        
        if (mv <= rest + 1) {
            return tot;
        }
        return 2 * rest + 1;
    }
};