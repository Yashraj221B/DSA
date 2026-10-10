#include<bits/stdc++.h>

using namespace std;

/*
CANVAS
[0,0,1,1,1,2,2,3,3,4]
i = 0 j = 1
i = 0 j = 2
[0,1,0,1,1,2,2,3,3,4]
[0,1,2,3,4,5,6,7,8,9]
i = 1 j = 3
i = 1 j = 4
i = 1 j = 5
[0,1,2,1,1,0,2,3,3,4]
[0,1,2,3,4,5,6,7,8,9]
i = 2 j = 5
i = 2 j = 6
i = 2 j = 7
[0,1,2,3,1,0,2,1,3,4]
[0,1,2,3,4,5,6,7,8,9]
i = 3 j = 7
i = 3 j = 8
i = 3 j = 9
[0,1,2,3,4,0,2,1,3,1]
[0,1,2,3,4,5,6,7,8,9]
i = 4 j = 9
i = 4 j = 10 - END
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;
        int temp;
        while (j<nums.size())
        {
            if(nums[i] < nums[j]){
                i++;
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }else{
                j++;
            }
        }
        return i+1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
