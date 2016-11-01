class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> indices;
        stack<char> st;
        for(int i =0; i<s.length(); i++) {
        	if(s[i] == '(') {
        		st.push('(');
        		indices.push(i);
        	} else {
	        	if(st.top() == '(') {
	        		st.pop();
	        		indices.pop();
	        	}
        	}

        }
        int res = 0;
        int prev = 0, cur = 0;
        while(!indices.empty()) {
        	cur = indices.top();
        	res = max(res, cur - prev + 1);
        	prev = cur;
        	indices.pop();
        }
        res = max(s.length() - cur + 1, res);
        return res;
    }
};