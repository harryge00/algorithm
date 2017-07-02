func distributeCandies(candies []int) int {
	kinds := make(map[int]bool)
    for i, val := range candies {
    	kinds[val] = true
    }
    half := len(candies) / 2
    if len(kinds) >= half {
    	return half
    } else {
    	return len(kinds)
    }

}