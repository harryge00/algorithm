public class Solution {
    public int[] twoSum(int[] nums, int target) {
        int [] res = new int[2];
        for(int i = 0; i < nums.length; i++) {
            int a = nums[i];
            for(int j = i + 1; j < nums.length; j++) {
            	if(a + nums[j] == target) {
            		res[0] = i + 1;
            		res[1] = j + 1;
            		return res;
            	}
            }
        }
    }
    
}