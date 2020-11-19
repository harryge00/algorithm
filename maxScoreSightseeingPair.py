class Solution:
    def maxScoreSightseeingPair(self, A: List[int]) -> int:
        # Input: [8,1,5,2,6] i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11
        # 1 3 8 2 4 5 11 3
        # 80 80 x x x x x 88
        # 8,1,5,2,6
        # 0,1,2,3,4
        # 0,1,2,2,2
        # 8,1,5,2,6
        res = 0
        n = len(A)
        maxRightScore = A[n - 1] - n + 1
        for i in range(n - 2, -1, -1):
            # print(i, res, maxRightScore)
            res = max(res, A[i] + i + maxRightScore)
            maxRightScore = max(maxRightScore, A[i] - i)

        return res