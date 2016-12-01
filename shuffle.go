package main
import (
	"fmt"
	"math/rand"
)
type Solution struct {
    Origin [] int 
}


func Constructor(nums []int) Solution {
    return Solution{Origin: nums}
}


/** Resets the array to its original configuration and return it. */
func (this *Solution) Reset() []int {
    return this.Origin
}


/** Returns a random shuffling of the array. */
func (this *Solution) Shuffle() []int {
	n := len(this.Origin)
    res := make([]int, n)
    for i := range res {
    	res[i] = this.Origin[i]
    }
    // for i, count := n - 1; i < n; i++, count-- {
    // 	indices[i] = rand.Intn(count)
    // }
    for j := 1; j < n; j++ {
    	i := rand.Intn(j)
    	tmp := res[i]
    	res[i] = res[j]
    	res[j] = tmp
    }
    return res
}


/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.Reset();
 * param_2 := obj.Shuffle();
 */

 func main() {
 	s:= Constructor([]int{3, 4, 5, 6, 7, 8})
 	fmt.Println(s.Reset())
 	fmt.Println(s.Shuffle())
 	fmt.Println(s.Reset())
 }