class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        target = sum(nums)
        if target % 2 == 1:
            return False
        target //= 2
        dp = set([0])
        for n in nums:
            dp2 = dp.copy()
            for x in dp:
                y = x + n
                if y == target:
                    return True
                if y < target:
                    dp2.add(y)
            dp = dp2
        
        return False