func lengthOfLongestSubstring(s string) int {
    m := make(map[string]bool)
    record := make([]int)
    i := 0
    for c := range strings.Split(s, "") {
    	if m[c] {
    		record = append(record, i)
    	}
    	i++
    }
}