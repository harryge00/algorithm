class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        n = len(piles)
        records = [[0 for _ in range(n)] for _ in range(n)]

        def helper(piles: List[int]) -> int:
            n = len(piles)
            if n == 2:
                return max(piles[0], piles[1])
            if records[0][n - 1] > 0:
                return records[0][n - 1]

            getLeftResult = piles[0]
            if piles[1] > piles[n - 1]:
                getLeftResult += helper(piles[2:])
            else:
                getLeftResult += helper(piles[1 : n - 1])
            
            getRightResult = piles[n - 1]
            if piles[0] > piles[n - 2]:
                getRightResult += helper(piles[1: n - 1])
            else:
                getRightResult += helper(piles[0 : n - 2])
            
            records[0][n] 
            return max(getLeftResult, getRightResult)

        return 2 * helper(piles) > sum(piles)
        # 1 8 2 7 3
        # 3 2 
        # 2 9 3 7 4
        # 4 5 8 9
        # 4 98 5 99 6
        # 4 + [5 99 6], 6 + [4 98 5]
        # 4 + 5 + [6], 6 +
        # 
        # 15 29 16

        # 88 99 33 22 55
        # dp[i][j] = max(
        # piles[i] + dp[i + 2][j]
        # piles[i] + dp[i + 1][j - 1]
        # piles[j] + dp[i + 1][j - 1]
        # piles[j] + dp[i][j - 2]
        # )
        # dp[0][n - 1] > sum - dp[0][n - 1]
        # dp[]
        # 3 5 6 7
        n = len(piles)
        if n <= 2:
            return True

        l, r = 0, n - 1
        scoreAlex, scoreLee = 0, 0
        dp = [[0 for _ in range(n)] for _ in range(n)]
        q = []
        q.append()
        while True:
            dp[l][r] = piles[] max()
            

        return 2 * dp[0][n - 1] > sum(piles)
        

