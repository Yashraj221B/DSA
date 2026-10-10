class Solution:
    def __init__(self):
        self.count = 0

    def findArr(self, arr:str, zero: int, one: int, limit: int):
        if zero == 0 and one == 0:
            if arr.find("0"*(limit+1)) == -1 and arr.find("1"*(limit+1)) == -1:
                # print("OK:", arr)
                self.count+=1
            # else:
                # print("ER:", arr)
            return arr
        
        if(zero != 0):
            self.findArr(arr + '0', zero-1, one, limit)
        if(one != 0):
            self.findArr(arr + '1', zero, one-1, limit)
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        self.findArr("", zero, one, limit)
        return self.count        

if __name__ == '__main__':
    s = Solution()
    print(s.numberOfStableArrays(17,12,96))
