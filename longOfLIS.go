func lengthOfLIS(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
    dp := make([]int, len(nums))
    dp[0] = nums[0]
    lastIndex := 0
    for i := 1; i < len(nums); i++ {
    	if nums[i] < dp[lastIndex] {
    		binaryInsert(dp, nums[i], lastIndex)
    	} else {
    		lastIndex++
    		nums[lastIndex] = nums[i]
    	}
    }
    return lastIndex + 1
}

/*
1 2 6 8 10 13
*/

func binaryInsert(arr []int, num int, lastIndex int) {
	l, r := 0, lastIndex
	m := (l + r) / 2
	for l < r {
		if arr[m] == num {
			break
		}
		if arr[m] > num && (m == 0 || arr[m - 1] < num) {
			break
		}
		if arr[m] < num {
			l = m + 1
		} else {
			r = m - 1
		}
        m = (l + r) / 2
	}
	arr[m] = num
}