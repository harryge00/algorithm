public class Solution {
    public int search(int[] nums, int target) {    
        int l = 0, r = nums.length - 1;
        while(l < r) {
            int m = l + (r - l) / 2;
            if(target == nums[m]) return m;
            if(target > nums[m]) {
                if(nums[l] < nums[r]) {
                    //in order
                    l = m + 1;
                }
                else if(nums[r] >= target) {
                    //in right part
                    l = m + 1;
                }
                else { //if(nums[r] < target) {
                    // may be in the left
                    if(nums[l] < nums[m]) {
                        //max in the right 
                        l = m + 1;
                    }
                    else 
                        r = m - 1;
                }
            } else { // target < nums[m]
                if(nums[l] < nums[r]) {
                    r = m - 1;
                }
                else if(nums[l] > target) {
                    if(nums[r] > nums[m])
                        r = m - 1;
                    else
                        l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        if(nums[l] == target) return l;
        else return -1;
    }    
}