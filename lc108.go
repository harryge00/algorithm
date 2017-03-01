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
type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func generateNode(nums []int, lo, hi int) *TreeNode{
	if(lo == hi) {
		return &TreeNode{
			Val: nums[lo],
		}
	} 
	if(lo > hi) {
		return nil;
	}
	m := lo + (hi - lo) / 2
	n := &TreeNode{Val:nums[m]}
	n.Left = generateNode(nums, lo, m - 1)
	n.Right = generateNode(nums, m+1, hi)
	return n
}

func sortedArrayToBST(nums []int) *TreeNode {
	return generateNode(nums, 0, len(nums) - 1)   
}

func main() {
	arr := []int{1,3, 5, 6, 9}
	n := sortedArrayToBST(arr)
	fmt.Println(n)
}