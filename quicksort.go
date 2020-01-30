package main
import "fmt"


func main() {
	nums := []int{3, 5, 1, 2, 9, 0, 100, 6, 88, 123, -2 , 34}
    /*
        3 5 1 2 0 9 100 6
        3 5 1 2 0 6 100 9
        0 5 1 2 3
          5 1 2 3
          2 1 5 3
        3 5 1 2 0 9 100 6
        0 1 2 3 5 6 9   100
    */
    fmt.Println(nums)
    sort(nums, 0, len(nums) - 1)
    fmt.Println(nums)

}

func sort(nums []int, lo int, hi int) {
    if lo >= hi {
        return
    }
    k := partition(nums, lo, hi)
    // fmt.Println(k, nums)
    sort(nums, lo, k - 1)
    // fmt.Println(nums)

    sort(nums, k + 1, hi)
    // fmt.Println(nums)

}

func swap(nums []int, a, b int) {
    tmp := nums[a]
    nums[a] = nums[b]
    nums[b] = tmp
}
func partition(nums []int, lo, hi int) int {
    pivot := nums[hi]
    i := lo
    j := hi - 1
    for true {
        for ;nums[i] < pivot; i++ {
            if(i == hi) {
                break
            }
        }
        for ;nums[j] > pivot; j-- {
            if(j == lo) {
                break
            }
        }
        if j <= i {
            break
        }
        swap(nums, i, j)
        if i < hi {
            i++
        }
        if j >= lo {
            j--
        }
    }
    swap(nums, i, hi)
    return i
}