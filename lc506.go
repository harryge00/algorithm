package main

func findRelativeRanks(nums []int) []string {
    res := make([]string, len(nums))
    ranks := make([]int, len(nums))
    for i, val := range nums {
    	highestRank := 10001
    	for j := 0; j < i; j++ {
    		if nums[i] > nums[j] {
    			if ranks[j] < highestRank {
    				highestRank = ranks[j]
    			}
    			ranks[j]++
    		} else {
    			break
    		}
    	}
    	if highestRank == 10001 {
    		ranks[j] = i
    	} else {
	    	ranks[j] = highestRank
    	}
    }
    for i, val := range ranks {
    	ranks[i]
    }
    return res
}

func main() {

}