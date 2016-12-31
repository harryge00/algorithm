func arrangeCoins(n int) int {
	i := 1
    for n >= i {
    	n -= i
    	i++
    }
    return i-1
}