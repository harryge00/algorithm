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

func search(nums []int, target int) int {
    l, r := 0, len(nums) - 1
    var m int
    for l <= r {
        m = (l + r) / 2
        if nums[m] == target {
            return m
        } else if nums[m] < target {
            if nums[l] < nums[r] {
                l = m + 1
            } else if nums[l] > target {
                l = m + 1
            } else {

            }
        }
        m = (l + r) / 2
    }
    return -1
}