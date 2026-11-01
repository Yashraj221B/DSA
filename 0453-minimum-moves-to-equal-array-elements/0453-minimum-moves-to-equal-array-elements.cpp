class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m = nums[0];
        int moves = 0;
        for(int i: nums){
            m = min(m, i);
        }
        for(int i: nums){
            moves += i - m;
        }
        return moves;
    }
};