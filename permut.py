from typing import List


class Solution:
    def gen(self, arr):
        if len(arr) == len(self.nums):
            print(arr)
            self.permutes.append(arr)
            return

        for i in self.nums:
            if i not in arr:
                self.gen(arr+[i])

    def permute(self, nums: List[int]) -> List[List[int]]:
        self.nums = nums
        self.permutes = []
        self.gen([])
        return self.permutes
    
if __name__ == "__main__":
    s = Solution()
    s.permute([1,2,3])