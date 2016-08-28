import java.util.*;
public class subsets {
     public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new LinkedList<List<Integer>>();
        
        for(int i = 0; i < nums.length; i++) {
            addSubset(res, new LinkedList<Integer>(Arrays.asList(nums[i])), nums, i);
        }
        res.add(new LinkedList<Integer>());        
        return res;
    }
    private void addSubset(List<List<Integer>> res, LinkedList<Integer> subset, int[] nums, int index) {
        //LinkedList<Integer> newsubset = subset;
        res.add((LinkedList<Integer>) subset.clone());
        
        if(index < nums.length - 1) {
            //not the last element
            for(int i = index + 1; i < nums.length; i++) {
                subset.offer(nums[i]);
                addSubset(res, subset, nums, i);
                subset.pollLast();
            }
        }
    }
    
}
