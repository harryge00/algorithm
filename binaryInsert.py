def binaryInsert(nums, n):
    l, r = 0, len(nums) - 1
    while l < r:
        m = (l + r) // 2
        # 1 4 19 23 44 /5
        # 0 1 2  3  4 /5
        if nums[m] == n:
            nums.insert(m, n)
            return
        if nums[m] < n:
            l = m + 1
        else:
            r = m - 1
    nums.insert(l + 1, n)
    return