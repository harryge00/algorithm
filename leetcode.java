import java.io.*;
import java.util.*;
/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
/*public class Solution{
    public void connect(TreeLinkNode root) {
        if(root == null || root.left == null || root.right == null)
            return;
        root.left.next = root.right;
        if(root.next != null)
            root.right.next = root.next.left;
        else
            root.right.next = null;
    }
}*/
public class leetcode
{
    public static Stack<Integer> sort(Stack<Integer> s)
    {
        
        Stack<Integer> r = new Stack<Integer>();
        int tmp;
        r.push(s.pop());
        while(!s.isEmpty()) {
            if(r.peek() >= s.peek())
                r.push(s.pop());
            else
            {
                tmp = s.pop();
                while(!r.isEmpty()) {
                    s.push(r.pop());
                }
                r.push(tmp);
            }
        }
        while(!r.isEmpty()){
            System.out.println(r.peek());
            s.push(r.pop());
        }
        return s;
    }
    public static int myAtoi(String str) {
        if(str == null)
        return 0;
        long res = 0;
        int i = 0;
        while(i < str.length() && str.charAt(i) ==' ') {
            i++;
        }
        if(i == str.length())
            return 0;
        boolean sign = false;
        if(str.charAt(i) == '-' )
        {
            sign = true;
            i++;
        }
        else if(str.charAt(i) == '+')
            i++;
        while(i < str.length() && str.charAt(i) <= '9' && str.charAt(i) >= '0') {
            res *=10;
            res += str.charAt(i) - '0';
            System.out.println(res);
            i++;
        }
        if(res > Integer.MAX_VALUE)
            return sign?Integer.MIN_VALUE : Integer.MAX_VALUE;
        
        return (int)res;
        
    }
    static class Solution {
    public static int maxProfit(int[] prices) {
        if(prices == null || prices.length < 2)
        return 0;
        int [] currMax = new int[prices.length];
        currMax[0] = 0;
        boolean flag = false;
        for(int i = 0; i < prices.length - 1; i++) {
            if(prices[i] < prices[i+1]) { flag =true; break;}
        }
        if(flag == false){
            System.out.println("descending");
            return 0;
        }
        for(int i = 1; i < prices.length; i++) {
            currMax[i] = Math.max(prices[i] - prices[0], currMax[i-1]);
        }
        for(int i = 1; i < prices.length - 1; i++) {
            for(int j = i + 1; j < prices.length; j++) {
                if(prices[j] - prices[i] > 0)
                    currMax[j] = Math.max(prices[j] - prices[i] + currMax[i-1], (currMax[j-1]>currMax[j]?currMax[j-1]:currMax[j]));
                else 
                    currMax[j] = Math.max(currMax[j], currMax[j-1]);
            }
        }
        return currMax[currMax.length-1];
    }
    }
    public static List<Integer> grayCode(int n) {
    List<Integer> result = new LinkedList<>();
    for (int i = 0; i < 1<<n; i++) result.add(i ^ i>>1);
    return result;
}
    public static void main(String args[])
    {
        int [] d = {4, 1 ,2};
       
       Solution.maxProfit(d); 
       int [] kk={10000, 9999, 9998, 9997};
       Solution.maxProfit(kk);
       int n = 1;
       System.out.println(1<<3);
       System.out.println(n>>1);
       System.out.println(grayCode(3).toString());

    }
}
