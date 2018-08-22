package main
import "fmt"

func rotate(nums []int, k int)  {
	count := 0
	var pre, start, tmp, j int
	n := len(nums)
	if k >= n {
		k = k % n
	}
	if k == 0 {
		return
	}
    for i := 0; count < n; i++ {
    	start = i
    	pre = nums[start]
   		j = (i + k) % n
   		for j != start {
   			count++
   			tmp = nums[j]
   			nums[j] = pre
   			pre = tmp
   			j += k
   			if j >= n {
   				j %= n
   			}
   		}
   		count++
   		nums[start] = pre
    }
}

func main() {
	arr := []int{0, 1,2, 3, 4, 5, 6, 7}
	rotate(arr, 5)
	fmt.Println(arr)
}