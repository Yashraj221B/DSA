class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        alice = [sum(days[:int(arriveAlice.split("-")[0])-1])+int(arriveAlice.split("-")[1]),
                 sum(days[:int(leaveAlice.split("-")[0])-1])+int(leaveAlice.split("-")[1])]
        bob = [sum(days[:int(arriveBob.split("-")[0])-1])+int(arriveBob.split("-")[1]),
               sum(days[:int(leaveBob.split("-")[0])-1])+int(leaveBob.split("-")[1])]
        # print(alice, bob)
        return max(0, min(alice[1], bob[1]) - max(alice[0], bob[0]) + 1)