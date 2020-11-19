package main
import "fmt"
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
// 背包0-1
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func knapsack(values []int, weights []int, limit int) int{
	// dp(i, W) = max(dp(i - 1, W), dp(i - 1, W - weights[i]) + values[i]
	// dp[]
	dp := make([]int, limit + 1)
	fmt.Println(values, weights)
	// curMax := 0 // Used to improve performance
	// 10 3 20 44 5
	// 20 5 25 48 6
	// 
	for i := range(values) {
		for w := limit - weights[i]; w >= 0; w-- {
			nextW := w + weights[i]
			//  

			// if nextW > limit {
			// 	continue
			// }
			// if nextW > curMax {
			// 	curMax = nextW
			// }
			dp[nextW] = max(dp[w] + values[i], dp[nextW])
		}
		
	}
	return dp[limit]
}

func main() {
	fmt.Println(knapsack([]int{60, 100, 120}, []int{10,20,30}, 50))
	fmt.Println(knapsack([]int{20, 5, 25,48,6}, []int{10, 3, 20, 44, 5}, 50))
	fmt.Println(knapsack([]int{20, 30, 44,55,60}, []int{20, 30, 40, 50, 60}, 100))
}