class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[256];
        int res = 0;
        int last = 0;
        for(int i = 0; i < s.length(); i++) {
        	if(arr[s[i]] > 0) {
        		int start = max(last, arr[s[i]]);
        		if(i - start > res) {
        			res = i - start;
        		}
        		if(arr[s[i]] > last) {
        			last = arr[s[i]];
        		}
        	}
    		arr[s[i]] = i;
        }
    	return res;
    }
};