func largeGroupPositions(s string) [][]int {
	var res [][]int
	startIndex := 0
    for i := range s {
		if i == 0 {
			continue
		}
		if s[i] != s[i - 1] {
			if i - startIndex > 2 {
				res = append(res, []int{startIndex, i - 1})
			}
			startIndex = i
		}
	}
	if len(s) - startIndex > 2 {
		return append(res, []int{startIndex, len(s) - 1})
	}
	return res
	// "abcdddeeeeaabbbcd"
}