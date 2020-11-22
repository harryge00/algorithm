class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        def binaryInsert(nums, n):
            l, r = 0, len(nums) - 1
            while l < r:
                m = (l + r) // 2
                # 1 4 19 23 44 /5
                # 0 1 2  3  4 /5
                # 1 6 7 # 5
                # 
                if nums[m] == n:
                    nums.insert(m + 1, n)
                    return nums
                if nums[m] < n:
                    l = m + 1
                else:
                    r = m - 1
            nums.insert(l + 1, n)
            return nums

        stones.sort()
        n = len(stones)
        while n > 1:
            newStone = stones[n - 1] - stones[n - 2]
            if newStone == 0:
                stones = stones[0: n - 2]
                n -= 2
            else:
                sstones = binaryInsert(stones[0:n - 2], stones[n - 1] - stones[n - 2])
                n -= 1
        
        return stones[0]