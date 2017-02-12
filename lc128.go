package main
import "fmt"
// 6 5 3 2 1 4
func longestConsecutive(nums []int) int {
	res := 0
	m := make(map[int]int)
 	for i := 0; i < len(nums); i++ {
 		m[nums[i]] = 1
 	}
 	for i := 0; i < len(nums); i++ {
 		if m[nums[i]] == 1 {
 			length := 1
 			left := nums[i] - 1
 			for m[left] > 0 {
 				length++
 				delete(m, left)
 				left--
 			}
 			right := nums[i] + 1
 			for m[right] > 0 {
 				length++
 				delete(m, right)
 				right--
 			}
 			if length > res {
 				res = length
 			}
 		}
 		if res > len(m) {
 			break
 		}
 	}
 	return res
}
func main() {
	fmt.Println(longestConsecutive([]int{6, 5, 3, 2, 1, 4}))
}