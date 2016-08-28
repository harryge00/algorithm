#include <iostream>
#include <climits>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0, end = 0, minLen = INT_MAX;
        string res = s;
        while(end < s.length()) {
            while(end < s.length() && !containsAllChars(t, s.substr(start, end - start + 1))) end++;
            if(end == s.length()) break;
            while(start < end && containsAllChars(t, s.substr(start, end - start + 1))) start++;
            if(end - start + 2 < minLen) {
                res = s.substr(start - 1, end - start + 2);
                minLen = end - start + 2;
                //cout << res << endl;
            }
            
        }
        if(minLen < INT_MAX) return res;
        else    return "";
    }
    bool containsAllChars(string undertest, string str) {
        int m = 0;
        bool flag = true;
        while(flag && m < undertest.length()) {
                //cout << undertest[m] << " " << str[n] << endl;
            flag = false;
            int n = 0;
            while(n < str.length()) {
                if(str[n++] == undertest[m]) {
                    flag = true;
                    m++;
                    break;
                }
            };
        }
        //cout << undertest <<" " <<str <<" " <<m <<" "<< undertest.length()<<endl;
        return m == undertest.length();
    }
};

int main() {
    string s = "ADOBECODEBANC", t = "CBA";
    Solution sol;
    std::cout<<sol.minWindow(s, t)<<endl;
}
