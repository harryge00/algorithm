// my first program in C++
#include <iostream>
#include <climits>
#include <string.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
	    if (numRows <= 1)
    		return s;

	    const int len = (int)s.length();
	    string *str = new string[numRows];

	    int row = 0, step = 1;      
	    for(int i = 0; i < len; i++) {
	    	str[row].push_back(s[i]);
	    	row += step;
	    	if(row == numRows-1) {
	    		step = - step;
	    	}
	    }
	    string res;
	    for(int i = 0; i < numRows; i++) {
	    	res += str[i];
	    }
	    return res;
    }
};
int main()
{
	cout<<"hello"<<endl;
    Solution s;
    cout<<s.convert("PAYPALISHIRING", 3);

}