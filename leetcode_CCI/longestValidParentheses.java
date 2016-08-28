public class Solution {
    public int longestValidParentheses(String s) {
        boolean consistent = false;
        int max = 0;
        int matched = 0;
        int leftPs = 0;
        for(int i = 0; i < s.length(); i++) {
        	if(s.charAt(i) == '(') {
    		    if(!consistent) {
    				consistent = true;
    			}
        		leftPs++;

        	} else if(s.charAt(i) == ')') {
        	    if(leftPs == 0 && consistent) {
        	    	consistent = false;
        	    	max = max > matched ? max : matched;
        	    	mathced = 0;
        	    }
        		if(leftPs > 0) {
        			matched++;
        			leftPs--;

        		}
        	}
        }
        return 2*(max > matched ? max : matched);
    }
}