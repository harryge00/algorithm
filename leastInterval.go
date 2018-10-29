func leastInterval(tasks []byte, n int) int {
    m := make(map[byte][int])
    max := 0
    for _, task := range tasks {
    	m[task] += 1
    	if m[task] > max {
    		max = m[task]
    	}
    }
    res, kind := 0, len(m)
    for {
    	if kind < n {
    		return res + max * n 
    	}
    }
}