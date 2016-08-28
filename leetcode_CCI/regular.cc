#include <iostream>
#include <string>
using namespace std;

class Solution {

public:

    bool isMatch(string s, string p) {

        return s == p;

    }

};

int main() {
	Solution s;
	cout<<s.isMatch("abcd", "a.*d");
}
