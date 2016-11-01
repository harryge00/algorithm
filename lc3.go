package main
import "fmt"
import "strings"
func lengthOfLongestSubstring(s string) int {
    m := make(map[string]int)
    res := 0
    for i, c := range strings.Split(s, "") {
    	if _, ok := m[c]; ok {
    		tmp := i - m[c] + 1
    		if tmp > res {
    			res = tmp
    		}
    	}
		m[c] = i
    }
    return res
}

func main() {
	lengthOfLongestSubstring("avdfadfef")
}