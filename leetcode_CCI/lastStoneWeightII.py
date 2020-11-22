class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        # pick[j][i] = 1 if pick[j-1][i - stones[j]]
        # 2 1 1
        # 3 11 8
        n = len(stones)
        dp = [set() for _ in range(n//2)]
        s = sum(stones)

        for cur in stones:
            for j in range(len(dp) - 1, 0, -1):
                for last in dp[j - 1]:
                    dp[j].add(last + cur)
            
            dp[0].add(cur)

        # 4 6 7 1 3
        # 21
        res = 9999
        for x in dp[n//2 - 1]:
            res = min(abs(2 * x - s), res)
        
        return res