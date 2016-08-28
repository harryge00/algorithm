import java.util.*;
public class sum3 {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if(nums.length < 3)
        return res;
        Arrays.sort(nums);
        if(nums[0] > 0 || nums[nums.length - 1] < 0) return res;
        int start = 0, end = nums.length - 1;
        while(start < end) {
            int s = nums[start] + nums[end];
            if(s > 0) {
                int i = start + 1;
                while((i < end - 1) && (nums[i + 1] == nums[start])) i++; // move i until nums[i] is the last element == nums[start]
                while(i < end && nums[i] + s < 0) {
                    i++;
                }
                if(nums[i] + s == 0) {
                    List<Integer> tmp = new ArrayList<Integer>();
                    tmp.add(nums[start]);
                    tmp.add(nums[i]);
                    tmp.add(nums[end]);
                    res.add(tmp);
                }
                end--;
                
            }
            else {
                int i = end - 1;
                while((i > start + 1 ) && (nums[i - 1] == nums[end])) 
                    i--;
                while(i > start && (nums[i] + s > 0) ) i--;
                if(nums[i] + s == 0) {
                    List<Integer> tmp = new ArrayList<Integer>();
                    tmp.add(nums[start]);
                    tmp.add(nums[i]);
                    tmp.add(nums[end]);
                    res.add(tmp);
                }
                start++;
            }            
        }
        return res;
    }
    public static void main(String[] args) {
        sum3 sss= new sum3();
        int [] nums = {-1, 0, 1, 2, -1, -4};
        List<List<Integer>> res = sss.threeSum(nums);
        for(List<Integer> list : res) {
            System.out.println(list.toString());
        }
    }
}