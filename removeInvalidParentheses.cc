class Solution {
	/*
	Input: "()())()"
	Output: ["()()()", "(())()"]
	*/
public:
    unordered_set<string> validSet;
    vector<string> removeInvalidParentheses(string s) {
    	int left = 0, right = 0;
        for(int i = 0; i < s.size(); i++) {
        	if(s[i] == '(') {
        		left++;
        	} else if(s[i] == ')') {
        		if(left) {
        			left--;
        		} else {
        			right++;
        		}
        	}
        }
        travelString(s, 0, 0, 0, left, right, "");
        vector<string> ans;
        for(unordered_set<string>::iterator it = validSet.begin(); it != validSet.end(); it++) {
        	ans.push_back(*it);
        }
        return ans;

    }
    void travelString(string s, int index, int nl, int nr, int left, int right, string curStr) {
    	if(index == s.size()) {
    		if(left == 0 && right == 0) {
    			validSet.insert(curStr);
    		}
    		return;
    	}
    	if(s[index] == '(' ) {
    		if(left) {
    			travelString(s, index + 1, nl, nr, left - 1, right, curStr);
    		}
    		travelString(s, index + 1, nl + 1, nr, left + 1, right, curStr + '(');
    	} else if(s[index] == ')') {
    		if(right) {
	    		travelString(s, index + 1, nl, nr, left, right - 1, curStr);
    		}
    		if(nl) {
	    		travelString(s, index + 1, nl - 1, nr, left, right, curStr + ')');
    		}
    	} else {
	    	travelString(s, index + 1, nl, nr, left, right, curStr + s[index]);
    	}
    }
};