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

func getMin(a, b, c int) int {
    if a < b {
        if c < a {
            return c
        } else {
            return a
        }
    } else {
        if c < b {
            return c
        } else {
            return b
        }
    }
}

func maximalSquare(matrix [][]byte) int {
    m := len(matrix)
    n := len(matrix[0])
    var arr [][]int
    for i := 0; i < m; i++ {
        row := make([]int, n)
        arr = append(arr, row)
    }
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if i == 0 || j == 0 {
                if matrix[i][j] == 1 {
                    arr[i][j] = 1
                    if max < 1 {
                        max = 1
                    }
                } else {
                    arr[i][j] = 0
                }
            } else {
                if matrix[i][j] == 1 {
                    arr[i][j] = getMin(arr[i][j-1], arr[i - 1][j], arr[i - 1][j - 1]) + 1
                    if max < arr[i][j] {
                        max = arr[i][j]
                    }
                }
            }
            // fmt.Printf("%d,", arr[i][j])
        }
        // fmt.Println(" ")
    }
    
    return max*max
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
    fmt.Println([]byte{1,1,0,1})
 	s:= Constructor([]int{3, 4, 5, 6, 7, 8})
 	fmt.Println(s.Reset())
 	fmt.Println(s.Shuffle())
 	fmt.Println(s.Reset())
 }