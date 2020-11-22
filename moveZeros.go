func moveZeroes(nums []int)  {
    l := 0
    for i := range(nums) {
        if nums[i] == 0 {
            continue
		}
		nums[l] = nums[i]
        l++
    }
	for i := l; i < len(nums); i++ {
		nums[i] = 0
	}
}