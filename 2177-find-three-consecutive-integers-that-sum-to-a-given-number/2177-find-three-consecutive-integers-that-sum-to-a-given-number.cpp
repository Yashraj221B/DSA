class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num%3 == 0){
            long long rem = num/3;
            return {rem-1, rem, rem+1}; 
        }
        return {};
    }
};