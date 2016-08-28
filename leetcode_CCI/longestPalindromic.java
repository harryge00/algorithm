import java.util.*;
import java.io.*;

public class longestPalindromic {
    public String longestPalindrome(String s) {
        HashMap<Character, List<Integer>> map = new HashMap<Character, List<Integer>>();
        for(int i = 0; i < s.length(); i++) {
        	char c = s.charAt(i);
        	if(map.containsKey(c)) {
        		List<Integer> list = map.get(c);
        		list.add(i);//reference?
        	} else {
        		List<Integer> list = new ArrayList<Integer>();
        		list.add(i);
        		map.put(c, list);
        	}
        }
        String res = "";
        for(List<Integer> list : map.values()) {
        	if(list.size() < 2) continue;
        	for(int i = 0; i < list.size(); i++) {
        		int start = list.get(i);
        		boolean needbreak = false;
	        	for(int j = list.size() - 1; j > i; j--) {
	        		int end = list.get(j);
	        		if(end - start < res.length()) {
	        			needbreak = true;
	        			break;
	        		}
	        		int substrlen = (end - start) / 2;
	        		int k = 0;
	        		for(; k < substrlen; k++) {
	        			if(s.charAt(start+k) != s.charAt(end-k)) {
	        				break;
	        			}
	        		}
	        		if(k == substrlen) res= s.substring(start, end+1);
	        		// String substr = s.substring(start, start+substrlen);
	        		// String substr2 = s.substring(start+substrlen+1, end+1);
	        		// System.out.println(substr+start+","+end+" "+substr2);
	        		// if(substr.equals(substr2)) {
	        		// 	res = s.substring(start, end+1);
	        		// }
	        	}
	        	if(needbreak) break;        		
        	}
        	// System.out.println(list.toString());
        }
        return res;
    }
    public static void main(String[] args) {
    	longestPalindromic test = new longestPalindromic();
    	System.out.println(test.longestPalindrome("abcdcbaeee"));
    	System.out.println(test.longestPalindrome("kfkabcdcbaeee"));
    }
}